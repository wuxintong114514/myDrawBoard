#ifndef GLOBAL_H
#define GLOBAL_H
#include<QPointF>
#include<QString>


class Global
{
    //Q_OBJECT
public:
    Global();
    static QPointF pointDragEnter;
    static QString currentFileName;
    static bool resizeDragging;
    static float zIndex;
};

#endif // GLOBAL_H
