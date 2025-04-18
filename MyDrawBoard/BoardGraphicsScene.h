#ifndef BOARDGRAPHICSSCENE_H
#define BOARDGRAPHICSSCENE_H
#include<QGraphicsScene>
#include<QGraphicsSceneDragDropEvent>


class BoardGraphicsScene : public QGraphicsScene
{
    //Q_OBJECT
public:
    BoardGraphicsScene();
protected:
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
};

#endif // BOARDGRAPHICSSCENE_H
