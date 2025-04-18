#ifndef BOARDGRAPHICSVIEW_H
#define BOARDGRAPHICSVIEW_H

#include <QGraphicsView>
#include<QDragEnterEvent>
#include<QDropEvent>
#include<QMouseEvent>
#include"global.h"

class BoardGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    // 添加接收 QWidget* 参数的构造函数
    BoardGraphicsView(QWidget *parent=0);
signals:
    void mousemoved(QPoint);
    void mousepressed(QPoint);
    void mousereleased();
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // BOARDGRAPHICSVIEW_H
