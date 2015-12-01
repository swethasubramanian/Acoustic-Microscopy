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
    QByteArrayData data[8];
    char stringdata[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_bsc_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_bsc_t qt_meta_stringdata_bsc = {
    {
QT_MOC_LITERAL(0, 0, 3), // "bsc"
QT_MOC_LITERAL(1, 4, 11), // "acquireData"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 12), // "getParentDir"
QT_MOC_LITERAL(4, 30, 12), // "scanSettings"
QT_MOC_LITERAL(5, 43, 13), // "getSampleData"
QT_MOC_LITERAL(6, 57, 13), // "getPlanarData"
QT_MOC_LITERAL(7, 71, 7) // "saveDir"

    },
    "bsc\0acquireData\0\0getParentDir\0"
    "scanSettings\0getSampleData\0getPlanarData\0"
    "saveDir"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_bsc[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,

       0        // eod
};

void bsc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        bsc *_t = static_cast<bsc *>(_o);
        switch (_id) {
        case 0: _t->acquireData(); break;
        case 1: _t->getParentDir(); break;
        case 2: _t->scanSettings(); break;
        case 3: _t->getSampleData(); break;
        case 4: _t->getPlanarData(); break;
        case 5: { QString _r = _t->saveDir();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
