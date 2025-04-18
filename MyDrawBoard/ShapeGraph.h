#ifndef SHAPEGRAPH_H
#define SHAPEGRAPH_H

#include <QPointF>
#include <QColor>
#include <Qt>

class shapeGraph
{
    //Q_OBJECT
public:
    // 构造函数，添加参数用于初始化图形属性
    shapeGraph(const QString& type, const QPointF& pos, qreal width, qreal height,
               int penWidth, Qt::PenStyle penStyle, const QColor& penColor,
               const QColor& brushColor, qreal scale, qreal rotation, qreal zValue);

    // 访问器方法
    QString getType() const;
    QPointF getPos() const;
    qreal getWidth() const;
    qreal getHeight() const;
    int getPenWidth() const;
    Qt::PenStyle getPenStyle() const;
    QColor getPenColor() const;
    QColor getBrushColor() const;
    qreal getScale() const;
    qreal getRotation() const;
    qreal getZValue() const;
private:
    QString Gtype;  // 图形类型
    QPointF SPos;   // 图形位置
    qreal Width;    // 图形宽度
    qreal Height;   // 图形高度
    int PenWidth;   // 线条宽度
    Qt::PenStyle PenStyle; // 线条样式
    QColor PenColor;  // 线条颜色
    QColor BrushColor; // 填充颜色
    qreal Scale;    // 缩放比例
    qreal Rotation; // 旋转角度
    qreal ZValue;   // Z 值
};

#endif // SHAPEGRAPH_H
