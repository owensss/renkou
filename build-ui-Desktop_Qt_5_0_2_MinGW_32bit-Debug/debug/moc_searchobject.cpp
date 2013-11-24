/****************************************************************************
** Meta object code from reading C++ file 'searchobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ui/searchobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SearchObject_t {
    QByteArrayData data[7];
    char stringdata[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SearchObject_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SearchObject_t qt_meta_stringdata_SearchObject = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 16),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 1),
QT_MOC_LITERAL(4, 33, 16),
QT_MOC_LITERAL(5, 50, 15),
QT_MOC_LITERAL(6, 66, 19)
    },
    "SearchObject\0areaComboChanged\0\0s\0"
    "yearComboChanged\0okButtonClicked\0"
    "searchButtonClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SearchObject[] = {

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
       4,    1,   37,    2, 0x08,
       5,    0,   40,    2, 0x08,
       6,    0,   41,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SearchObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SearchObject *_t = static_cast<SearchObject *>(_o);
        switch (_id) {
        case 0: _t->areaComboChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->yearComboChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->okButtonClicked(); break;
        case 3: _t->searchButtonClicked(); break;
        default: ;
        }
    }
}

const QMetaObject SearchObject::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SearchObject.data,
      qt_meta_data_SearchObject,  qt_static_metacall, 0, 0}
};


const QMetaObject *SearchObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SearchObject.stringdata))
        return static_cast<void*>(const_cast< SearchObject*>(this));
    if (!strcmp(_clname, "UiItem"))
        return static_cast< UiItem*>(const_cast< SearchObject*>(this));
    return QDialog::qt_metacast(_clname);
}

int SearchObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
