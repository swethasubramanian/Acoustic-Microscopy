/****************************************************************************
** Meta object code from reading C++ file 'acquisition.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "acquisition.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'acquisition.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_acquisition_t {
    QByteArrayData data[13];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_acquisition_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_acquisition_t qt_meta_stringdata_acquisition = {
    {
QT_MOC_LITERAL(0, 0, 11), // "acquisition"
QT_MOC_LITERAL(1, 12, 13), // "workRequested"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 23), // "waveformUpdateRequested"
QT_MOC_LITERAL(4, 51, 15), // "runIndexChanged"
QT_MOC_LITERAL(5, 67, 8), // "finished"
QT_MOC_LITERAL(6, 76, 13), // "statusChanged"
QT_MOC_LITERAL(7, 90, 6), // "status"
QT_MOC_LITERAL(8, 97, 15), // "waveformUpdated"
QT_MOC_LITERAL(9, 113, 15), // "QVector<double>"
QT_MOC_LITERAL(10, 129, 13), // "getPlanarData"
QT_MOC_LITERAL(11, 143, 13), // "getSampleData"
QT_MOC_LITERAL(12, 157, 7) // "acquire"

    },
    "acquisition\0workRequested\0\0"
    "waveformUpdateRequested\0runIndexChanged\0"
    "finished\0statusChanged\0status\0"
    "waveformUpdated\0QVector<double>\0"
    "getPlanarData\0getSampleData\0acquire"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_acquisition[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    1,   63,    2, 0x06 /* Public */,
       8,    2,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   71,    2, 0x0a /* Public */,
      11,    0,   72,    2, 0x0a /* Public */,
      12,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void acquisition::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        acquisition *_t = static_cast<acquisition *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->workRequested(); break;
        case 1: _t->waveformUpdateRequested(); break;
        case 2: _t->runIndexChanged(); break;
        case 3: _t->finished(); break;
        case 4: _t->statusChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->waveformUpdated((*reinterpret_cast< const QVector<double>(*)>(_a[1])),(*reinterpret_cast< const QVector<double>(*)>(_a[2]))); break;
        case 6: _t->getPlanarData(); break;
        case 7: _t->getSampleData(); break;
        case 8: _t->acquire(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
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
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&acquisition::waveformUpdateRequested)) {
                *result = 1;
            }
        }
        {
            typedef void (acquisition::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&acquisition::runIndexChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (acquisition::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&acquisition::finished)) {
                *result = 3;
            }
        }
        {
            typedef void (acquisition::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&acquisition::statusChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (acquisition::*_t)(const QVector<double> & , const QVector<double> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&acquisition::waveformUpdated)) {
                *result = 5;
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
    if (!strcmp(_clname, qt_meta_stringdata_acquisition.stringdata0))
        return static_cast<void*>(const_cast< acquisition*>(this));
    return QObject::qt_metacast(_clname);
}

int acquisition::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void acquisition::workRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void acquisition::waveformUpdateRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void acquisition::runIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void acquisition::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void acquisition::statusChanged(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void acquisition::waveformUpdated(const QVector<double> & _t1, const QVector<double> & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
