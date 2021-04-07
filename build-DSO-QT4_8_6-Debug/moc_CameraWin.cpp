/****************************************************************************
** Meta object code from reading C++ file 'CameraWin.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DSO/UI/CameraWin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CameraWin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CameraWin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      25,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,   10,   10,   10, 0x08,
      55,   10,   10,   10, 0x08,
      76,   10,   10,   10, 0x08,
      97,   10,   10,   10, 0x08,
     112,  107,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CameraWin[] = {
    "CameraWin\0\0camera_quit()\0start()\0"
    "on_start_Bt_clicked()\0on_quit_Bt_clicked()\0"
    "on_save_Bt_clicked()\0display()\0arg1\0"
    "on_comboBox_currentIndexChanged(QString)\0"
};

void CameraWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CameraWin *_t = static_cast<CameraWin *>(_o);
        switch (_id) {
        case 0: _t->camera_quit(); break;
        case 1: _t->start(); break;
        case 2: _t->on_start_Bt_clicked(); break;
        case 3: _t->on_quit_Bt_clicked(); break;
        case 4: _t->on_save_Bt_clicked(); break;
        case 5: _t->display(); break;
        case 6: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CameraWin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CameraWin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CameraWin,
      qt_meta_data_CameraWin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CameraWin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CameraWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CameraWin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CameraWin))
        return static_cast<void*>(const_cast< CameraWin*>(this));
    return QWidget::qt_metacast(_clname);
}

int CameraWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
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
