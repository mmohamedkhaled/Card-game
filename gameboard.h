#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include<QVector>
#include<QGraphicsPixmapItem>

#include"card.h"


class gameboard
{
private:




public:
    QVector <QVector<card>> grid;
    int rows;
    int cols;
    gameboard();
    void draw();
};

#endif // GAMEBOARD_H
