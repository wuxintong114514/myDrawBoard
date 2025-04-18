// DrawBoard.h
#ifndef MYDRAWBOARD_H
#define MYDRAWBOARD_H

#include <QMainWindow>
#include<QLayout>
#include<QMessageBox>
#include<QLabel>
#include<QPushButton>
#include<QComboBox>
#include<QSpinBox>
#include"ShapeButton.h"
#include"BoardGraphicsScene.h"
#include"global.h"
#include<QGraphicsItem>
#include<QInputDialog>
#include<QColorDialog>
#include<QFileDialog>
#include"ShapeGraph.h"
#include"ui_DrawBoard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class MyDrawBoard : public QMainWindow
{
    Q_OBJECT

public:
    MyDrawBoard(QWidget *parent = nullptr);
    ~MyDrawBoard();
    void initUi();
    void getZIndex(QGraphicsItem *item);
    void addItemToScene(QGraphicsItem *item);
    void updateTbrStyle();
    void clearScene();
    void loadBoard();
    bool saveBoard();
    bool saveBoardAsPic();
private slots:
    void toolButtonClicked(QAction *tb);
    void setBrushColor();
    void setPenWidth();
    void setPenColor();
    void setPenStyle();
    void setTextFont();
    void setFontSize();
    void setTextBold();
    void setTextItalic();
    void setTextColor();
    void onZoomIn();
    void onZoomOut();
    void onRotateLeft();
    void onRotateRight();
    void onDelete();
    void drawEllipse();
    void drawRect();
    void drawLine();
    void drawText();
    void updateStatus(QPoint point);
    void onMousePress(QPoint point);
    void onMouseMove(QPoint point);
    void onMouseRelease();
    void repaintItem(QPoint point);
private:
    Ui::mainWindow *ui;
    QGraphicsItem *item;
    QAction *tbNew, *tbOpen, *tbSave, *tbSaveAsPic;
    QLabel *label, *lbStatus;
    QPushButton *pbBrushColor, *pbPenColor, *pbBold, *pbItalic, *pbTextColor, *pbZoomIn, *pbZoomOut, *pbRotateLeft, *pbRotateRight, *pbDelete;
    QComboBox *cobPenWidth, *cobPenStyle, *cobFont;
    QSpinBox *sbFontSize;
    ShapeButton *pbEllipse, *pbRect, *pbLine, *pbText;
    BoardGraphicsScene *scene;
};
#endif // MYDRAWBOARD_H
