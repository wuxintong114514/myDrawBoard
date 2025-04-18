#include "BoardGraphicsView.h"
#include<QMouseEvent>

// 实现接收 QWidget* 参数的构造函数
BoardGraphicsView::BoardGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    // 可以在这里添加额外的初始化代码

}
void BoardGraphicsView::mouseMoveEvent(QMouseEvent *event){
    QPoint pointMouseMove = event->pos();
    emit mousemoved(pointMouseMove);
    if(Global::resizeDragging == false)
        QGraphicsView::mouseMoveEvent(event);
}

void BoardGraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void BoardGraphicsView::dropEvent(QDropEvent *event)
{
    Global::pointDragEnter = event->posF();
    setFocus();
}

void BoardGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::LeftButton)
    {
        QPoint pointMousePress = event->pos();
        emit mousepressed(pointMousePress);
    }
    QGraphicsView::mousePressEvent(event);
}

void BoardGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    if(Global::resizeDragging == true)
    {
        emit mousereleased();
    }
    QGraphicsView::mouseReleaseEvent(event);
}


