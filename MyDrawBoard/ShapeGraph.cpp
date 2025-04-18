#include "ShapeGraph.h"

// 构造函数的实现，初始化成员变量
shapeGraph::shapeGraph(const QString& type, const QPointF& pos, qreal width, qreal height,
                       int penWidth, Qt::PenStyle penStyle, const QColor& penColor,
                       const QColor& brushColor, qreal scale, qreal rotation, qreal zValue)
    : Gtype(type), SPos(pos), Width(width), Height(height),
      PenWidth(penWidth), PenStyle(penStyle), PenColor(penColor),
      BrushColor(brushColor), Scale(scale), Rotation(rotation), ZValue(zValue)
{
}

// 获取图形类型的方法
QString shapeGraph::getType() const
{
    return Gtype;
}

// 获取图形位置的方法
QPointF shapeGraph::getPos() const
{
    return SPos;
}

// 获取图形宽度的方法
qreal shapeGraph::getWidth() const
{
    return Width;
}

// 获取图形高度的方法
qreal shapeGraph::getHeight() const
{
    return Height;
}

// 获取线条宽度的方法
int shapeGraph::getPenWidth() const
{
    return PenWidth;
}

// 获取线条样式的方法
Qt::PenStyle shapeGraph::getPenStyle() const
{
    return PenStyle;
}

// 获取线条颜色的方法
QColor shapeGraph::getPenColor() const
{
    return PenColor;
}

// 获取填充颜色的方法
QColor shapeGraph::getBrushColor() const
{
    return BrushColor;
}

// 获取缩放比例的方法
qreal shapeGraph::getScale() const
{
    return Scale;
}

// 获取旋转角度的方法
qreal shapeGraph::getRotation() const
{
    return Rotation;
}

// 获取 Z 值的方法
qreal shapeGraph::getZValue() const
{
    return ZValue;
}
