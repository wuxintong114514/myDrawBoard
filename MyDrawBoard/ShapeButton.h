#ifndef SHAPEBUTTON_H
#define SHAPEBUTTON_H
#include<QPushButton>
#include<QMouseEvent>
#include<QMimeData>//QMimeData 常被用于实现拖放操作、剪贴板操作等数据传输功能
#include<QDrag>//主要用于执行拖放操作


class ShapeButton : public QPushButton
{
    Q_OBJECT
public:
    ShapeButton();
protected:
    void mouseMoveEvent(QMouseEvent *event);
private:
    QMimeData *mimeData;
    QDrag *drag;
};

#endif // SHAPEBUTTON_H
