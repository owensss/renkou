#include "SchemeBuffer.hpp"
#include "Scheme.hpp"
#include "schememetadata.h"
#include <ctime>
#include <cstdio>
#include <cstring>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QTextCodec>
#include <windows.h>
#include <utility> // std::swap
// #define _DEBUG_
#ifdef _DEBUG_

#include <QDebug>
#ifndef DEBUG
#define DEBUG(statement) {qDebug() << "[DBG]"<<statement;}
#endif

#endif
// #include "configMan.hpp"

namespace {
    bool processLine(QTextStream& in, char * buffer, schememetadataPtr meta, size_t& offset) {
        // static const size_t buffer_size = 10000;
        if (in.atEnd()) return false;

        QStringList list = in.readLine().split(",");
        schInt i;
        schDouble f;
        // if year not exist
        // FIX: start year could be READ_START_YEAR or USER_SPECIFIC START_YEAR
        if (list[0].toInt()-(int)(meta->startYear()) > (int)(offset) ) {
            // set all to zero
            qDebug() << "greater than" << list[0].toInt() << meta->startYear() << offset;
            memset(buffer, 0, meta->rowSize());
            return false;
        } else if (list[0].toInt()-(int)(meta->startYear()) < (int)(offset) ) {
            qDebug() << "less than" << list[0].toInt() << meta->startYear() << offset;
            --offset; // skip this one
            return false;
        }


        for (unsigned j = 1; j <= meta->colCount(); ++j) {
            switch (meta->colAt(j).getfield_type()) {
                case metadataItem::NONE:
                    break;
                case metadataItem::INT:
                    i = list[j-1].toInt();
                    memcpy(buffer+meta->colOffset(j), &i, meta->colSize(j));
                    break;
                case metadataItem::DOUBLE:
                    f = list[j-1].toDouble();
                    memcpy(buffer+meta->colOffset(j), &f, meta->colSize(j));
                    break;
                case metadataItem::STRING:
                    memcpy(buffer+meta->colOffset(j), (list[j-1].toStdString().c_str()), meta->colSize(j));
                    break;
                default:
                    break;
            } // end of switch
        } // end of for(each col)

        return true;

    } // ENDOF processLine
    /*
    bool processLine(char** in, char * buffer, schememetadataPtr meta, size_t offset) {
        // static const size_t buffer_size = 10000;
        if (**in == '\0') return false;

        char* line = *in;

        char* line_end = strchr(*in, '\n');
        if (line_end==NULL) line_end = strchr(*in, '\0');

        *in = line_end;


        int j = 1;
        schInt i;
        schDouble f;
        schString str;
        char* tk = strtok(line, ",");

        sscanf(tk, "%d", &i);

        if (i-meta->startYear() != offset) {
            memset(buffer, 0, meta->rowSize());
            qDebug() << "row missing at" << meta->name();
            return false;
        }

        while (tk != NULL && line < line_end) {
            int len = strlen(tk);
            if (tk[len]=='\n') tk[len] = '\0';
            switch (meta->colAt(j).getfield_type()) {
                case metadataItem::NONE:
                    break;
                case metadataItem::INT:
                    schInt specific handler
                    sscanf(tk, "%d", &i);
                    memcpy(buffer+meta->colOffset(j), &i, meta->colSize(j));
                    break;
                case metadataItem::DOUBLE:
                    sscanf(tk, "%lf", &f);
                    f = list[j-1].toDouble();
                    memcpy(buffer+meta->colOffset(j), &f, meta->colSize(j));
                    break;
                case metadataItem::STRING:
                    memcpy(buffer+meta->colOffset(j), tk, meta->colSize(j));
                    break;
                default:
                    break;
            } // end of switch
            ++j;
            strtok(NULL, ",");
        }

        if (j-meta->startYear() != meta->colCount()) {
            memset(buffer, 0, meta->rowSize());
            qDebug() << "col count mismatch at" << meta->name();
            return false;
        }

        *in = line_end+1;
        return true;

    } // ENDOF processLine
    */
}

SchemeBuffer::SchemeBuffer(void)
{
    // allocate each buffer
    for (size_t i = 0 ; i < BUFFER_SIZE; ++i) {
        buffer.push_back(std::shared_ptr<Buffer>(new Buffer()));
    }
    // current occupied buffer
    buffer_full = 0;
}

SchemeBuffer::~SchemeBuffer() {
}

SchemeBuffer::BufferIter SchemeBuffer::exist(const Scheme* scheme) {
    // note : this might be changed
    QString name = scheme->toInternalName();
    auto end = buffer.end();
    for (auto i = buffer.begin(); i != end; ++i) {
        if ((*i)->getName() == name)
            return i;
    }

    return end;
}

schInt SchemeBuffer::toInt(const Scheme* scheme, size_t row, size_t col) {
    union {
        char buf[sizeof(schInt)];
        schInt res;
    } u ;
    // note: readData returns the pointer of the record in the buffer
    memcpy(u.buf, readData(scheme, row, col), sizeof(schInt));
    return u.res;
}

schDouble SchemeBuffer::toDouble(const Scheme* scheme, size_t row, size_t col) {
    union {
        char buf[sizeof(schDouble)];
        schDouble res;
    } u ;
    memcpy(u.buf, readData(scheme, row, col), sizeof(schDouble));
    return u.res;
}

schString SchemeBuffer::toString(const Scheme* scheme, size_t row, size_t col) {
    static const unsigned BUF_SIZE = 100;
    char buf[BUF_SIZE];
    strncpy(buf, readData(scheme, row, col), BUF_SIZE);
    // note: convert from GBK to utf8
    // if, in the future, the database provides utf8 encoding data, remove this line.
    auto codec = QTextCodec::codecForName("GBK");
    if (codec == nullptr) {
        qDebug() << "Codec GBK not exist, why?";
    }
    // set NULL
    buf[scheme->getMetadata()->colSize(col)] = 0;
    return schString(codec->toUnicode(buf));
}

void SchemeBuffer::forceRead(const Scheme* scheme) {
    loadScheme(scheme);
}

char * SchemeBuffer::readData(const Scheme* scheme, size_t row, size_t col) {
    auto index = exist(scheme);
    if (index == buffer.end()) { // if not in the buffer, loadit
        auto new_buffer=loadScheme(scheme);
        // index = loadData(scheme);
        return new_buffer->locate(row, col);
    }
    // mov front
    moveFront(index);
    return buffer.front()->locate(row, col);
}

SchemeBuffer::BufferPtr SchemeBuffer::loadScheme(const Scheme* scheme) {
    if ( buffer_full != BUFFER_SIZE ) { // buffer not full
        // insert into buffer one by one
        // get first empty buffer
        auto& target = buffer[buffer_full];
        // load data
        target->load(scheme);
        // move front & advance empty_buffer counter by 1
        buffer.move(buffer_full++, 0);
        return buffer.front();
    } else {
        // replace last
        auto& end = buffer.back();
        end->load(scheme);
        // buffer[index]->load(scheme);
        // mov front
        buffer.move(BUFFER_SIZE-1, 0);
        return buffer.front();
    }
}
//==============================================================
/******************** SchemeBuffer::Buffer ********************/
//==============================================================

bool SchemeBuffer::Buffer::load(const Scheme* scheme) {
    meta = scheme->getMetadata();
    if (! allocateBuffer(meta->size())) return false;
    if (! setData(scheme->toInternalName(), meta))
        return false;

    size = meta->size();
    name = scheme->toInternalName();
    last_access = time(0);

    return true;
}

bool SchemeBuffer::Buffer::allocateBuffer(size_t size) {
    if (size < buffer_size) return true;
    buffer_size = size;
    delete [] buffer;
    buffer = new char[buffer_size];
    if (buffer==nullptr) return false; // note: may throw bad_alloc
    return true;
}

/*
 * IO function
 */
bool SchemeBuffer::Buffer::setData(const QString& name, schememetadataPtr meta) {
    QFile fs(name);
    if (! fs.open(QIODevice::ReadOnly)) {
        throw RecordNotExist(name);
    }
    QTextStream in(&fs);
    // csv (comma sep)
    for (unsigned i = 0; i < meta->rowCount(); ++i) {
        processLine(in, buffer+i*meta->rowSize(), meta, i);
    }
    fs.close();
    return true;
}

/*
bool SchemeBuffer::Buffer::setData(const QString& name, schememetadataPtr meta) {
    QTextCodec* codec = QTextCodec::codecForLocale();
    std::string path = codec->fromUnicode((Config::config.value("DATA_PATH")+name).toStdString());
    ////////////////////
    HANDLE hFile = ::CreateFile(_T(path), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    HANDLE hFileMap;
    LPVOID pFileMap;
    char* file;

    hFileMap = CreateFileMapping (hFile,
        NULL,
        PAGE_READONLY,
        0,
        0,
        NULL);
    if (hFile == INVALID_HANDLE_VALUE){
        puts ("Can't mapping file\n");
        exit (1);
    }

    //Get the pointer of the mapping
    pFileMap = MapViewOfFile (hFileMap,
        FILE_MAP_READ,
        0,
        0,
        0);
    file = (char*) pFileMap;

    for (unsigned i = 0; i < meta->rowCount(); ++i) {
        processLine(file, buffer+i*meta->rowSize(), meta, i);
    }

    UnmapViewOfFile (pFileMap);
    CloseHandle (hFileMap);
    CloseHandle (hFile);
}
*/

char * SchemeBuffer::Buffer::locate(size_t row, size_t col) {
#ifdef _DEBUG_
    DEBUG("[locate]"<<"row"<<row<<"col"<<col)
#endif
    char * offset = 0;
    last_access = time(0);
    offset = buffer+(meta->rowSize()*(row-meta->startYear())+meta->colOffset(col));

    return offset;
}

SchemeBuffer::Buffer::Buffer(void)
    :last_access(0), size(0), buffer_size(INIT_SIZE), name(""), meta(nullptr), buffer(nullptr)
{
    buffer = new char[buffer_size];
}

SchemeBuffer::Buffer::~Buffer(void) {
    delete [] buffer;
}

