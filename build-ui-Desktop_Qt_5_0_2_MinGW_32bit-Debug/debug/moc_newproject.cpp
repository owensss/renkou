/****************************************************************************
** Meta object code from reading C++ file 'newproject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ui/newproject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newproject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NewProject_t {
    QByteArrayData data[7];
    char stringdata[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_NewProject_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_NewProject_t qt_meta_stringdata_NewProject = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 17),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 9),
QT_MOC_LITERAL(4, 40, 23),
QT_MOC_LITERAL(5, 64, 15),
QT_MOC_LITERAL(6, 80, 19)
    },
    "NewProject\0projectNameEdited\0\0_filename\0"
    "selectPathButtonClicked\0okButtonClicked\0"
    "cancelButtonClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewProject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08,
       4,    0,   37,    2, 0x08,
       5,    0,   38,    2, 0x08,
       6,    0,   39,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NewProject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewProject *_t = static_cast<NewProject *>(_o);
        switch (_id) {
        case 0: _t->projectNameEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->selectPathButtonClicked(); break;
        case 2: _t->okButtonClicked(); break;
        case 3: _t->cancelButtonClicked(); break;
        default: ;
        }
    }
}

const QMetaObject NewProject::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewProject.data,
      qt_meta_data_NewProject,  qt_static_metacall, 0, 0}
};


const QMetaObject *NewProject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewProject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewProject.stringdata))
        return static_cast<void*>(const_cast< NewProject*>(this));
    if (!strcmp(_clname, "UiItem"))
        return static_cast< UiItem*>(const_cast< NewProject*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewProject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
