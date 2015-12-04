/****************************************************************************
** Meta object code from reading C++ file 'bsc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "bsc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bsc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_bsc_t {
    QByteArrayData data[12];
    char stringdata[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_bsc_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_bsc_t qt_meta_stringdata_bsc = {
    {
QT_MOC_LITERAL(0, 0, 3), // "bsc"
QT_MOC_LITERAL(1, 4, 16), // "acquireScopeData"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "newValue"
QT_MOC_LITERAL(4, 31, 7), // "acquire"
QT_MOC_LITERAL(5, 39, 12), // "getParentDir"
QT_MOC_LITERAL(6, 52, 13), // "getParameters"
QT_MOC_LITERAL(7, 66, 16), // "getDataFromScope"
QT_MOC_LITERAL(8, 83, 5), // "value"
QT_MOC_LITERAL(9, 89, 8), // "movMotor"
QT_MOC_LITERAL(10, 98, 9), // "killMotor"
QT_MOC_LITERAL(11, 108, 14) // "stopAcquistion"

    },
    "bsc\0acquireScopeData\0\0newValue\0acquire\0"
    "getParentDir\0getParameters\0getDataFromScope\0"
    "value\0movMotor\0killMotor\0stopAcquistion"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_bsc[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   57,    2, 0x0a /* Public */,
       5,    0,   58,    2, 0x0a /* Public */,
       6,    0,   59,    2, 0x0a /* Public */,
       7,    1,   60,    2, 0x0a /* Public */,
       9,    0,   63,    2, 0x0a /* Public */,
      10,    0,   64,    2, 0x0a /* Public */,
      11,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void bsc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        bsc *_t = static_cast<bsc *>(_o);
        switch (_id) {
        case 0: _t->acquireScopeData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->acquire(); break;
        case 2: _t->getParentDir(); break;
        case 3: _t->getParameters(); break;
        case 4: _t->getDataFromScope((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->movMotor(); break;
        case 6: _t->killMotor(); break;
        case 7: _t->stopAcquistion(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (bsc::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bsc::acquireScopeData)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject bsc::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_bsc.data,
      qt_meta_data_bsc,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *bsc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bsc::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_bsc.stringdata))
        return static_cast<void*>(const_cast< bsc*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int bsc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void bsc::acquireScopeData(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
