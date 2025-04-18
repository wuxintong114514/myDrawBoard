/****************************************************************************
** Meta object code from reading C++ file 'DrawBoard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../DrawBoard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DrawBoard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyDrawBoard_t {
    QByteArrayData data[29];
    char stringdata0[321];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyDrawBoard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyDrawBoard_t qt_meta_stringdata_MyDrawBoard = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MyDrawBoard"
QT_MOC_LITERAL(1, 12, 17), // "toolButtonClicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "QAction*"
QT_MOC_LITERAL(4, 40, 2), // "tb"
QT_MOC_LITERAL(5, 43, 13), // "setBrushColor"
QT_MOC_LITERAL(6, 57, 11), // "setPenWidth"
QT_MOC_LITERAL(7, 69, 11), // "setPenColor"
QT_MOC_LITERAL(8, 81, 11), // "setPenStyle"
QT_MOC_LITERAL(9, 93, 11), // "setTextFont"
QT_MOC_LITERAL(10, 105, 11), // "setFontSize"
QT_MOC_LITERAL(11, 117, 11), // "setTextBold"
QT_MOC_LITERAL(12, 129, 13), // "setTextItalic"
QT_MOC_LITERAL(13, 143, 12), // "setTextColor"
QT_MOC_LITERAL(14, 156, 8), // "onZoomIn"
QT_MOC_LITERAL(15, 165, 9), // "onZoomOut"
QT_MOC_LITERAL(16, 175, 12), // "onRotateLeft"
QT_MOC_LITERAL(17, 188, 13), // "onRotateRight"
QT_MOC_LITERAL(18, 202, 8), // "onDelete"
QT_MOC_LITERAL(19, 211, 11), // "drawEllipse"
QT_MOC_LITERAL(20, 223, 8), // "drawRect"
QT_MOC_LITERAL(21, 232, 8), // "drawLine"
QT_MOC_LITERAL(22, 241, 8), // "drawText"
QT_MOC_LITERAL(23, 250, 12), // "updateStatus"
QT_MOC_LITERAL(24, 263, 5), // "point"
QT_MOC_LITERAL(25, 269, 12), // "onMousePress"
QT_MOC_LITERAL(26, 282, 11), // "onMouseMove"
QT_MOC_LITERAL(27, 294, 14), // "onMouseRelease"
QT_MOC_LITERAL(28, 309, 11) // "repaintItem"

    },
    "MyDrawBoard\0toolButtonClicked\0\0QAction*\0"
    "tb\0setBrushColor\0setPenWidth\0setPenColor\0"
    "setPenStyle\0setTextFont\0setFontSize\0"
    "setTextBold\0setTextItalic\0setTextColor\0"
    "onZoomIn\0onZoomOut\0onRotateLeft\0"
    "onRotateRight\0onDelete\0drawEllipse\0"
    "drawRect\0drawLine\0drawText\0updateStatus\0"
    "point\0onMousePress\0onMouseMove\0"
    "onMouseRelease\0repaintItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyDrawBoard[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  134,    2, 0x08 /* Private */,
       5,    0,  137,    2, 0x08 /* Private */,
       6,    0,  138,    2, 0x08 /* Private */,
       7,    0,  139,    2, 0x08 /* Private */,
       8,    0,  140,    2, 0x08 /* Private */,
       9,    0,  141,    2, 0x08 /* Private */,
      10,    0,  142,    2, 0x08 /* Private */,
      11,    0,  143,    2, 0x08 /* Private */,
      12,    0,  144,    2, 0x08 /* Private */,
      13,    0,  145,    2, 0x08 /* Private */,
      14,    0,  146,    2, 0x08 /* Private */,
      15,    0,  147,    2, 0x08 /* Private */,
      16,    0,  148,    2, 0x08 /* Private */,
      17,    0,  149,    2, 0x08 /* Private */,
      18,    0,  150,    2, 0x08 /* Private */,
      19,    0,  151,    2, 0x08 /* Private */,
      20,    0,  152,    2, 0x08 /* Private */,
      21,    0,  153,    2, 0x08 /* Private */,
      22,    0,  154,    2, 0x08 /* Private */,
      23,    1,  155,    2, 0x08 /* Private */,
      25,    1,  158,    2, 0x08 /* Private */,
      26,    1,  161,    2, 0x08 /* Private */,
      27,    0,  164,    2, 0x08 /* Private */,
      28,    1,  165,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   24,
    QMetaType::Void, QMetaType::QPoint,   24,
    QMetaType::Void, QMetaType::QPoint,   24,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   24,

       0        // eod
};

void MyDrawBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyDrawBoard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toolButtonClicked((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 1: _t->setBrushColor(); break;
        case 2: _t->setPenWidth(); break;
        case 3: _t->setPenColor(); break;
        case 4: _t->setPenStyle(); break;
        case 5: _t->setTextFont(); break;
        case 6: _t->setFontSize(); break;
        case 7: _t->setTextBold(); break;
        case 8: _t->setTextItalic(); break;
        case 9: _t->setTextColor(); break;
        case 10: _t->onZoomIn(); break;
        case 11: _t->onZoomOut(); break;
        case 12: _t->onRotateLeft(); break;
        case 13: _t->onRotateRight(); break;
        case 14: _t->onDelete(); break;
        case 15: _t->drawEllipse(); break;
        case 16: _t->drawRect(); break;
        case 17: _t->drawLine(); break;
        case 18: _t->drawText(); break;
        case 19: _t->updateStatus((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 20: _t->onMousePress((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 21: _t->onMouseMove((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 22: _t->onMouseRelease(); break;
        case 23: _t->repaintItem((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyDrawBoard::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MyDrawBoard.data,
    qt_meta_data_MyDrawBoard,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyDrawBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyDrawBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyDrawBoard.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MyDrawBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
