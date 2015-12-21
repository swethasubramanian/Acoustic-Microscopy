/****************************************************************************
** Meta object code from reading C++ file 'acquisition.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "acquisition.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'acquisition.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_acquisition_t {
    QByteArrayData data[9];
    char stringdata[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_acquisition_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_acquisition_t qt_meta_stringdata_acquisition = {
    {
QT_MOC_LITERAL(0, 0, 11), // "acquisition"
QT_MOC_LITERAL(1, 12, 13), // "workRequested"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "runIndexChanged"
QT_MOC_LITERAL(4, 43, 8), // "finished"
QT_MOC_LITERAL(5, 52, 13), // "statusChanged"
QT_MOC_LITERAL(6, 66, 6), // "status"
QT_MOC_LITERAL(7, 73, 13), // "getPlanarData"
QT_MOC_LITERAL(8, 87, 13) // "getSampleData"

    },
    "acquisition\0workRequested\0\0runIndexChanged\0"
    "finished\0statusChanged\0status\0"
    "getPlanarData\0getSampleData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_acquisition[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   50,    2, 0x0a /* Public */,
       8,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void acquisition::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        acquisition *_t = static_cast<acquisition *>(_o);
        switch (_id) {
        case 0: _t->workRequested(); break;
        case 1: _t->runIndexChanged(); break;
        case 2: _t->finished(); break;
        case 3: _t->statusChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->getPlanarData(); break;
        case 5: _t->getSampleData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (acquisition::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&acquisition::workRequested)) {
                *result = 0;
            }
        }
        {
            typedef void (acquisition::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&acquisition::runIndexChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (acquisition::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&acquisition::finished)) {
                *result = 2;
            }
        }
        {
            typedef void (acquisition::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&acquisition::statusChanged)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject acquisition::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_acquisition.data,
      qt_meta_data_acquisition,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *acquisition::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *acquisition::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_acquisition.stringdata))
        return static_cast<void*>(const_cast< acquisition*>(this));
    return QObject::qt_metacast(_clname);
}

int acquisition::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void acquisition::workRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void acquisition::runIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void acquisition::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void acquisition::statusChanged(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
