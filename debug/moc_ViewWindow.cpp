/****************************************************************************
** Meta object code from reading C++ file 'ViewWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../view/ViewWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ViewWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ViewWindow_t {
    QByteArrayData data[11];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ViewWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ViewWindow_t qt_meta_stringdata_ViewWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ViewWindow"
QT_MOC_LITERAL(1, 11, 20), // "signalChangeEditMode"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "slotAdd"
QT_MOC_LITERAL(4, 41, 10), // "slotDelete"
QT_MOC_LITERAL(5, 52, 8), // "slotEdit"
QT_MOC_LITERAL(6, 61, 8), // "slotSave"
QT_MOC_LITERAL(7, 70, 10), // "slotCancel"
QT_MOC_LITERAL(8, 81, 11), // "slotRefresh"
QT_MOC_LITERAL(9, 93, 17), // "slotEnableButtons"
QT_MOC_LITERAL(10, 111, 14) // "QItemSelection"

    },
    "ViewWindow\0signalChangeEditMode\0\0"
    "slotAdd\0slotDelete\0slotEdit\0slotSave\0"
    "slotCancel\0slotRefresh\0slotEnableButtons\0"
    "QItemSelection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ViewWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    2,   66,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 10,    2,    2,
    QMetaType::Void,

       0        // eod
};

void ViewWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ViewWindow *_t = static_cast<ViewWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalChangeEditMode(); break;
        case 1: _t->slotAdd(); break;
        case 2: _t->slotDelete(); break;
        case 3: _t->slotEdit(); break;
        case 4: _t->slotSave(); break;
        case 5: _t->slotCancel(); break;
        case 6: _t->slotRefresh(); break;
        case 7: _t->slotEnableButtons((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 8: _t->slotEnableButtons(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ViewWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ViewWindow::signalChangeEditMode)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ViewWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ViewWindow.data,
      qt_meta_data_ViewWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ViewWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ViewWindow.stringdata0))
        return static_cast<void*>(const_cast< ViewWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ViewWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ViewWindow::signalChangeEditMode()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
