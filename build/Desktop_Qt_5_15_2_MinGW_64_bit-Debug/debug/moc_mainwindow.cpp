/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[325];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "InsertMediaFile"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 16), // "on_Begin_clicked"
QT_MOC_LITERAL(4, 45, 19), // "onItemDoubleClicked"
QT_MOC_LITERAL(5, 65, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 82, 4), // "item"
QT_MOC_LITERAL(7, 87, 22), // "showListWidgetMenuSlot"
QT_MOC_LITERAL(8, 110, 13), // "deleteAllData"
QT_MOC_LITERAL(9, 124, 11), // "GetDuration"
QT_MOC_LITERAL(10, 136, 12), // "upDateSlider"
QT_MOC_LITERAL(11, 149, 14), // "slot_PlayError"
QT_MOC_LITERAL(12, 164, 19), // "QMediaPlayer::Error"
QT_MOC_LITERAL(13, 184, 11), // "ChangeVoice"
QT_MOC_LITERAL(14, 196, 9), // "MoveVideo"
QT_MOC_LITERAL(15, 206, 21), // "on_volumeData_clicked"
QT_MOC_LITERAL(16, 228, 13), // "keyPressEvent"
QT_MOC_LITERAL(17, 242, 10), // "QKeyEvent*"
QT_MOC_LITERAL(18, 253, 5), // "event"
QT_MOC_LITERAL(19, 259, 28), // "on_Speed_currentIndexChanged"
QT_MOC_LITERAL(20, 288, 4), // "arg1"
QT_MOC_LITERAL(21, 293, 13), // "PlayNextMedia"
QT_MOC_LITERAL(22, 307, 17) // "PlayPreviousMedia"

    },
    "MainWindow\0InsertMediaFile\0\0"
    "on_Begin_clicked\0onItemDoubleClicked\0"
    "QListWidgetItem*\0item\0showListWidgetMenuSlot\0"
    "deleteAllData\0GetDuration\0upDateSlider\0"
    "slot_PlayError\0QMediaPlayer::Error\0"
    "ChangeVoice\0MoveVideo\0on_volumeData_clicked\0"
    "keyPressEvent\0QKeyEvent*\0event\0"
    "on_Speed_currentIndexChanged\0arg1\0"
    "PlayNextMedia\0PlayPreviousMedia"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    1,   91,    2, 0x08 /* Private */,
       7,    1,   94,    2, 0x08 /* Private */,
       8,    0,   97,    2, 0x08 /* Private */,
       9,    1,   98,    2, 0x08 /* Private */,
      10,    1,  101,    2, 0x08 /* Private */,
      11,    1,  104,    2, 0x08 /* Private */,
      13,    1,  107,    2, 0x08 /* Private */,
      14,    1,  110,    2, 0x08 /* Private */,
      15,    0,  113,    2, 0x08 /* Private */,
      16,    1,  114,    2, 0x08 /* Private */,
      19,    1,  117,    2, 0x08 /* Private */,
      21,    0,  120,    2, 0x08 /* Private */,
      22,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->InsertMediaFile(); break;
        case 1: _t->on_Begin_clicked(); break;
        case 2: _t->onItemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->showListWidgetMenuSlot((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: _t->deleteAllData(); break;
        case 5: _t->GetDuration((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 6: _t->upDateSlider((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 7: _t->slot_PlayError((*reinterpret_cast< QMediaPlayer::Error(*)>(_a[1]))); break;
        case 8: _t->ChangeVoice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->MoveVideo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_volumeData_clicked(); break;
        case 11: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 12: _t->on_Speed_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->PlayNextMedia(); break;
        case 14: _t->PlayPreviousMedia(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::Error >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
