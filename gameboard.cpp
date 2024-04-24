#include "gameboard.h"
#include "ui_gameboard.h"
#include "QGraphicsScene"





gameboard::gameboard()
{
    rows = 6;
    cols = 6;
    grid.resize(rows,QVector<card>(cols));

    for(int i = 0; i < 6; i++){
        for(int j =0; j < 6; j++){

            grid[i][j] = *new card;

        }

    }

    for(int i = 0; i < 6; i++){
        for(int j =0; j < 6; j++){

            grid[i][j].setState(0);

        }

    }










}


