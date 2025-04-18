/********************************************************************************
** Form generated from reading UI file 'DrawBoard.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWBOARD_H
#define UI_DRAWBOARD_H

#include <BoardGraphicsView.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QWidget *centralwidget;
    BoardGraphicsView *gvBoard;
    QStatusBar *statusbar;
    QToolBar *tbrFile;
    QToolBar *tbrStyle;
    QToolBar *tbrShape;

    void setupUi(QMainWindow *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QString::fromUtf8("mainWindow"));
        mainWindow->resize(1200, 800);
        centralwidget = new QWidget(mainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gvBoard = new BoardGraphicsView(centralwidget);
        gvBoard->setObjectName(QString::fromUtf8("gvBoard"));
        gvBoard->setGeometry(QRect(420, 260, 256, 192));
        mainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(mainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mainWindow->setStatusBar(statusbar);
        tbrFile = new QToolBar(mainWindow);
        tbrFile->setObjectName(QString::fromUtf8("tbrFile"));
        mainWindow->addToolBar(Qt::TopToolBarArea, tbrFile);
        tbrStyle = new QToolBar(mainWindow);
        tbrStyle->setObjectName(QString::fromUtf8("tbrStyle"));
        mainWindow->addToolBar(Qt::TopToolBarArea, tbrStyle);
        tbrShape = new QToolBar(mainWindow);
        tbrShape->setObjectName(QString::fromUtf8("tbrShape"));
        mainWindow->addToolBar(Qt::LeftToolBarArea, tbrShape);

        retranslateUi(mainWindow);

        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainWindow)
    {
        mainWindow->setWindowTitle(QCoreApplication::translate("mainWindow", "\346\210\221\347\232\204\347\273\230\345\233\276\346\235\277", nullptr));
        tbrFile->setWindowTitle(QCoreApplication::translate("mainWindow", "toolBar", nullptr));
        tbrStyle->setWindowTitle(QCoreApplication::translate("mainWindow", "toolBar", nullptr));
        tbrShape->setWindowTitle(QCoreApplication::translate("mainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWBOARD_H
