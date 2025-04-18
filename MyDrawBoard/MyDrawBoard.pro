QT       += core gui
QMAKE_CXXFLAGS += -fexceptions
QMAKE_LFLAGS_EXCEPTIONS = -Wl,-enable-stdcall-fixup
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BoardGraphicsScene.cpp \
    BoardGraphicsview.cpp \
    ShapeButton.cpp \
    ShapeGraph.cpp \
    global.cpp \
    main.cpp \
    DrawBoard.cpp

HEADERS += \
    BoardGraphicsScene.h \
    BoardGraphicsview.h \
    DrawBoard.h \
    ShapeButton.h \
    ShapeGraph.h \
    global.h

FORMS += \
    DrawBoard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    image/bigger.png \
    image/delete.png \
    image/dianxian.png \
    image/dianxianxian.png \
    image/dierxi.png \
    image/drawboard.png \
    image/fontcolor.png \
    image/jiacu.png \
    image/juxing.png \
    image/new.png \
    image/open.png \
    image/round.png \
    image/save.png \
    image/saveother.png \
    image/smaller.png \
    image/turnleft.png \
    image/turnright.png \
    image/wenzi.png \
    image/xieti.png \
    image/zhengchangxian.png \
    image/zhixian.png \
    image/zuicu.png \
    image/zuixi.png
