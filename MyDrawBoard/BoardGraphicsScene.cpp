#include "BoardGraphicsScene.h"
#include<QGraphicsScene>

BoardGraphicsScene::BoardGraphicsScene()
{
    setItemIndexMethod(QGraphicsScene::NoIndex);
}
void BoardGraphicsScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event){
    event->accept();
}
