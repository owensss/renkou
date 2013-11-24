#pragma once
#include <memory> // std::shared_ptr
#include <cstddef>
#include <string>
#include "SchemeDef.hpp"
#include <list>
#include "exceptions/RecordNotExist.hpp"

/**
 * note: Input: this class reads data from either file or database
 * 		stores it in binary form.
 * note: Store: LRU, least recently used method, stores the last access time
 * note: Output:
 * 		 if (scheme ! exists) replace one
 *
 * 		 read Metadata => start_address+length
 * 		 convert to output form
 */
class SchemeBuffer {
    private:
        class Buffer;
        typedef std::shared_ptr<Buffer> BufferPtr;
        typedef QList<BufferPtr> BufferList;
        typedef QList<BufferPtr>::iterator BufferIter;
        const static size_t BUFFER_SIZE = 1000;

    public:
        explicit SchemeBuffer(void);
        virtual ~SchemeBuffer() ;
        /**
         * @params: pointer to scheme, row and colonm of the data(row->year, col->indicator)
         * 			note: row starts with 0, say, year-start_year;
         * @return: the value of the desired type, do not check type information!
         * @impl: simply the combination of memcpy and union(for int and double).
         * 			as for strin, it's strcpy (copy till reaches '\0')
         */
        schInt    toInt(const Scheme* scheme, size_t row, size_t col);
        schString toString(const Scheme* scheme, size_t row, size_t col);
        schDouble toDouble(const Scheme* scheme, size_t row, size_t col);
        // force read a scheme into buffer
        void forceRead(const Scheme* scheme);
    private:
        /**
         * @params: schemePtr, row and col of the record (note: row->year, col->indicator)
         * 			note: row-> starts with 0, say, year-start_year.
         *          note: col-> starts with 1, the first element shall be value `year`.
         * @return: a pointer points to the begining of the record
         */
        char * readData(const Scheme* scheme, size_t row, size_t col);
    private:
        // replace data using LRU method
        BufferPtr loadScheme(const Scheme* scheme);
        /*
         * @impl: time complexity: O(N), linear search
         * @return: index if the scheme is already in the buffer, else return buffer.end()
         */
        BufferIter exist(const Scheme* scheme) /* const */; /* this function shall be called find... */
        // hey, you, there are two identifiers named buffer. don't mix them up
        BufferList buffer;
        size_t buffer_full;
        // LRU algo main function, move the recently used buffer to the front
        void moveFront(BufferIter buf) {
            if (buf == buffer.begin()) return;
            auto buf_store= *buf;
            buffer.erase(buf);
            buffer.push_front(buf_store);
        }
        // the buffer class that cares about IO, the SchemeBuffer class shall be responsible to the assignment of the buffer array
        /**
         * @description: this class reads data from either file or database and load it into memory
         * 		provides interface to access(read only) the mirrored data
         * 		it does not care about the type of the data
         */
        class Buffer {
            public:
                static const int INIT_SIZE = 1;
                Buffer();
                ~Buffer();
            public:
                /**
                 * @brief load scheme from Input device
                 * @return: true if success, false if failed
                 * @impl: set last_access, size, name, meta and reallocate the buffer on success
                 * XXX: communicate with the outer implement of the data storage method:
                 * 		file or database (currently communiate with file)
                 */
                bool load(const Scheme* scheme);
                // return the pointer points to the start position of the record
                // throw exception(?) on error
                char * locate(size_t row, size_t col);
                const QString& getName(void) const {return name;}
                size_t getSize(void) const {return size;}
                time_t lastAccess(void) const {return last_access;}
                schememetadataPtr getMetadata(void) const {return meta;}
                char * rawBuffer(void) {return buffer;}
            private:
                /**
                 * @brief :allocate new space for the buffer according to its size
                 * 			if new size <= buffer_size, then the size is not changed
                 * 			and the allocation shall not take place
                 * @return  false if allocation failed. however, it may throws bad_alloc
                 */
                bool allocateBuffer(size_t size) ;
                /**
                 * @desc:IO with filesystem or database, set data to buffer
                 * @params: the scheme name(shall be recegnizable by the implement), buffer, a pointer to the metadata
                 * @return : false if scheme not found
                 */
                bool setData(const QString& name, schememetadataPtr meta);
            private:
                time_t last_access;
                size_t size;
                size_t buffer_size;
                QString name; // the internal name of the scheme
                schememetadataPtr meta; // metadata of this scheme
                char * buffer;
        } ;
};

