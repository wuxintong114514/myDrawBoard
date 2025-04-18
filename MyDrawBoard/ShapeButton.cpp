#include "ShapeButton.h"

ShapeButton::ShapeButton()
{
}
void ShapeButton::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()!=Qt::MouseButton::LeftButton)
        return;
    mimeData = new QMimeData();
    drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setHotSpot(event->pos()-rect().topLeft());
    drag->exec(Qt::DropAction::MoveAction);
}
