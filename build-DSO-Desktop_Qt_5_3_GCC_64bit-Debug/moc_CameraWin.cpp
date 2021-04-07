/****************************************************************************
** Meta object code from reading C++ file 'CameraWin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DSO/UI/CameraWin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CameraWin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CameraWin_t {
    QByteArrayData data[8];
    char stringdata[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CameraWin_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CameraWin_t qt_meta_stringdata_CameraWin = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 11),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 5),
QT_MOC_LITERAL(4, 29, 19),
QT_MOC_LITERAL(5, 49, 18),
QT_MOC_LITERAL(6, 68, 18),
QT_MOC_LITERAL(7, 87, 4)
    },
    "CameraWin\0camera_quit\0\0start\0"
    "on_start_Bt_clicked\0on_quit_Bt_clicked\0"
    "on_save_Bt_clicked\0take"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraWin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CameraWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CameraWin *_t = static_cast<CameraWin *>(_o);
        switch (_id) {
        case 0: _t->camera_quit(); break;
        case 1: _t->start(); break;
        case 2: _t->on_start_Bt_clicked(); break;
        case 3: _t->on_quit_Bt_clicked(); break;
        case 4: _t->on_save_Bt_clicked(); break;
        case 5: _t->take(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CameraWin::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraWin::camera_quit)) {
                *result = 0;
            }
        }
        {
            typedef void (CameraWin::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraWin::start)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CameraWin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CameraWin.data,
      qt_meta_data_CameraWin,  qt_static_metacall, 0, 0}
};


const QMetaObject *CameraWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraWin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CameraWin.stringdata))
        return static_cast<void*>(const_cast< CameraWin*>(this));
    return QWidget::qt_metacast(_clname);
}

int CameraWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void CameraWin::camera_quit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CameraWin::start()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
