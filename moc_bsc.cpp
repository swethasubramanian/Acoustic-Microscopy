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
    QByteArrayData data[10];
    char stringdata[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_bsc_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_bsc_t qt_meta_stringdata_bsc = {
    {
QT_MOC_LITERAL(0, 0, 3), // "bsc"
QT_MOC_LITERAL(1, 4, 19), // "planarDataRequested"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 19), // "sampleDataRequested"
QT_MOC_LITERAL(4, 45, 15), // "startAcquistion"
QT_MOC_LITERAL(5, 61, 12), // "getParentDir"
QT_MOC_LITERAL(6, 74, 8), // "movMotor"
QT_MOC_LITERAL(7, 83, 9), // "killMotor"
QT_MOC_LITERAL(8, 93, 14), // "stopAcquistion"
QT_MOC_LITERAL(9, 108, 13) // "getCurrentRun"

    },
    "bsc\0planarDataRequested\0\0sampleDataRequested\0"
    "startAcquistion\0getParentDir\0movMotor\0"
    "killMotor\0stopAcquistion\0getCurrentRun"
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
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        case 0: _t->planarDataRequested(); break;
        case 1: _t->sampleDataRequested(); break;
        case 2: _t->startAcquistion(); break;
        case 3: _t->getParentDir(); break;
        case 4: _t->movMotor(); break;
        case 5: _t->killMotor(); break;
        case 6: _t->stopAcquistion(); break;
        case 7: _t->getCurrentRun(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (bsc::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bsc::planarDataRequested)) {
                *result = 0;
            }
        }
        {
            typedef void (bsc::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bsc::sampleDataRequested)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
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
void bsc::planarDataRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void bsc::sampleDataRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
