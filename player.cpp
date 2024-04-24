#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "player.h"
#include "card.h"
#include "mainwindow.h"
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>

player::player(MainWindow *mainView)
{
    colIndex = -1;
    rowIndex = 0;


    QPixmap playerPixmap(":/player.png");
    playerPixmap = playerPixmap.scaledToWidth(80);
    playerPixmap = playerPixmap.scaledToHeight(80);
    setPixmap(playerPixmap);
    mainWindow = mainView;

    pre = new card;
    preImage = new QGraphicsPixmapItem;
    pre = NULL;

    pre2 = new card;
    pre2Image = new QGraphicsPixmapItem;
    pre2 = NULL;





}

void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}



void player::keyPressEvent(QKeyEvent* event){

    setOpacity(1);
    if(event->key() == Qt::Key_Left){
        if(colIndex > 0 ){
            colIndex--;
            setPos(x()-75,y());

        }
    }

    else if(event->key() == Qt::Key_Right){

        if(colIndex < 5 ){
            colIndex++;
            setPos(x()+75,y());
            if(!visible) {
                this->setVisible(true);
                visible=1;
            }
        }
    }
    else if(event->key() == Qt::Key_Up){
        if(rowIndex > 0 ){
            rowIndex--;
            setPos(x(),y() - 100);
            if(!visible) {
                this->setVisible(true);
                visible=1;
            }
        }
    }

    else if(event->key() == Qt::Key_Down){
        if( rowIndex < 6 ){
            rowIndex++;
            setPos(x(),y() + 100);
            if(!visible) {
                this->setVisible(true);
                visible=1;
            }
        }
    }
    else if(event->key() == Qt::Key_S){
        if(mainWindow->pressed){
            for(int i =0; i<6; i++){
                for(int j = 0; j<6; j++){
                    mainWindow->drawBack(i,j);

                }
            }

            mainWindow->pressed = false;

        }
        else{
            for(int i =0; i<6; i++){
                for(int j = 0; j<6; j++){
                    mainWindow->drawFront(i,j);
                }
            }
            mainWindow->pressed = true;
        }
    }
    else if(event->key() == Qt::Key_Space){


        mainWindow->isGameOver();
        setOpacity(0);
        if(colIndex == -1){
            return;
        }
        else{
            if(pre == NULL){
                if(mainWindow->grid[rowIndex][colIndex]->getState() == 0){
                    mainWindow->grid[rowIndex][colIndex]->flip();
                    mainWindow->drawFront(rowIndex,colIndex);

                    pre = mainWindow->grid[rowIndex][colIndex];
                    preImage = &mainWindow->cards[rowIndex][colIndex];
                    preRow = rowIndex;
                    preCol = colIndex;

                }

            }
            else if(pre != NULL){
                pre2 = mainWindow->grid[rowIndex][colIndex];
                pre2Image = &mainWindow->cards[rowIndex][colIndex];
                pre2Row = rowIndex;
                pre2Col = colIndex;
                if(pre->getFront() == mainWindow->grid[rowIndex][colIndex]->getFront()){
                    mainWindow->grid[rowIndex][colIndex]->flip();
                    mainWindow->drawFront(rowIndex,colIndex);
                    delay();
                    mainWindow->scene->removeItem(preImage);
                    mainWindow->scene->removeItem(pre2Image);

                    mainWindow->score = mainWindow->score + 1;
                    mainWindow->lable1->setPlainText("Score: "+ QString::number(mainWindow->score));
                    mainWindow->openings = mainWindow->openings + 1;
                    mainWindow->lable2->setPlainText("Openings: "+QString::number(mainWindow->openings));


                }
                else {
                    mainWindow->grid[rowIndex][colIndex]->flip();
                    mainWindow->drawFront(rowIndex,colIndex);
                    delay();
                    mainWindow->grid[rowIndex][colIndex]->flip();
                    mainWindow->drawBack(pre2Row, pre2Col);
                    pre->flip();
                    mainWindow->drawBack(preRow, preCol);
                    mainWindow->openings = mainWindow->openings + 1;
                    mainWindow->lable2->setPlainText("Openings: "+QString::number(mainWindow->openings));


                }
                pre = NULL;
            }
        }


    }
}





