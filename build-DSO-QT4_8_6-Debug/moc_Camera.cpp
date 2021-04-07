/****************************************************************************
** Meta object code from reading C++ file 'Camera.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DSO/UI/Camera.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Camera.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Camera[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      31,   22,    7,    7, 0x08,
      54,    7,    7,    7, 0x08,
      75,    7,    7,    7, 0x08,
     101,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Camera[] = {
    "Camera\0\0camera_quit()\0id,image\0"
    "take_photo(int,QImage)\0on_startBt_clicked()\0"
    "on_photographBt_clicked()\0on_quitBt_clicked()\0"
};

void Camera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Camera *_t = static_cast<Camera *>(_o);
        switch (_id) {
        case 0: _t->camera_quit(); break;
        case 1: _t->take_photo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QImage(*)>(_a[2]))); break;
        case 2: _t->on_startBt_clicked(); break;
        case 3: _t->on_photographBt_clicked(); break;
        case 4: _t->on_quitBt_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Camera::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Camera::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Camera,
      qt_meta_data_Camera, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Camera::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Camera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Camera::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Camera))
        return static_cast<void*>(const_cast< Camera*>(this));
    return QWidget::qt_metacast(_clname);
}

int Camera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Camera::camera_quit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
