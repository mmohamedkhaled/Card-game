#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include "gameboard.h"
#include <QString>
#include <QFont>
#include "card.h"
#include "gameOver.h"
#include <QVector>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "iostream"
#include "player.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    rows = 6;
    cols = 6;
    grid.resize(rows,QVector<card*>(cols));
    openings = 0;
    score =0 ;
    winning = true;

    for(int i = 0; i < 6; i++){
        for(int j =0; j < 6; j++){
            card* tem= new card;
            grid[i][j] = tem;

        }

    }

    pressed = false;





    ui->setupUi(this);
    scene = new QGraphicsScene;
    view = new QGraphicsView;
    scene->setSceneRect(50, 50, 600, 600);
    ui->board->setScene(scene);
    QPixmap backGround(":/background.jpg");
    ui->flipCards->setStyleSheet("background-color-dark-gray");





    QGraphicsPixmapItem * background = new QGraphicsPixmapItem;
    background->setPixmap(backGround.scaled(800,800,Qt::KeepAspectRatio));
    background->setPos(-50,-50);
    scene->addItem(background);
    QPixmap back13(":/back.png");
    for (int i = 0; i < 6; i++)
    {
        for(int j = 0; j <6; j++){


            back13 = back13.scaledToWidth(75);
            back13 = back13.scaledToHeight(100);
            cards[i][j].setPixmap(back13);
            cards[i][j].setPos((100+(j*75)),(50+(i*100)));
            scene->addItem(&cards[i][j]);



        }

    }


    drawPlayer(50,60);
    lable1 = new QGraphicsTextItem;
    lable2 = new QGraphicsTextItem;

    lable1->setFont(QFont("times",16));
    lable1->setDefaultTextColor(Qt::green);
    lable1->setPlainText("Score: "+ QString::number(score));

    lable2->setFont(QFont("times",16));
    lable2->setDefaultTextColor(Qt::red);
    lable2->setPlainText("Openings: "+QString::number(openings));

    lable1->setPos(110,650);
    lable2->setPos(450,650);

    scene->addItem(lable1);
    scene->addItem(lable2);
    ui->board->show();



}


void MainWindow::drawPlayer(int rows, int cols){
    player* player1 = new player(this);
    player1->setPos(rows,cols);
    scene->addItem(player1);

    player1->setFlag(QGraphicsEllipseItem::ItemIsFocusable);
    player1->setFocus();

}


void MainWindow::drawBack(int i, int j){


    QPixmap back13(":/back.png");
    back13 = back13.scaledToWidth(75);
    back13 = back13.scaledToHeight(100);
    cards[i][j].setPixmap(back13);
    cards[i][j].setPos((100+(j*75)),(50+(i*100)));




}

void MainWindow::drawFront(int i, int j){


    if(grid[i][j]->getFront() == 1){

        QPixmap front1(":/front1.png");
        front1 = front1.scaledToWidth(75);
        front1 = front1.scaledToHeight(100);
        cards[i][j].setPixmap(front1);
        cards[i][j].setPos((100+(j*75)),(50+(i*100)));

    }

    if(grid[i][j]->getFront() == 2){

        QPixmap front2(":/front2.png");
        front2 = front2.scaledToWidth(75);
        front2 = front2.scaledToHeight(100);
        cards[i][j].setPixmap(front2);
        cards[i][j].setPos((100+(j*75)),(50+(i*100)));

    }

    if(grid[i][j]->getFront() == 3){

        QPixmap fron3(":/fron3.png");
        fron3 = fron3.scaledToWidth(75);
        fron3 = fron3.scaledToHeight(100);
        cards[i][j].setPixmap(fron3);
        cards[i][j].setPos((100+(j*75)),(50+(i*100)));

    }
    if(grid[i][j]->getFront() == 4){

        QPixmap front4(":/front4.png");
        front4 = front4.scaledToWidth(75);
        front4 = front4.scaledToHeight(100);
        cards[i][j].setPixmap(front4);
        cards[i][j].setPos((100+(j*75)),(50+(i*100)));

    }


}


void MainWindow::isGameOver(){
    if(openings > 39){
        winning = false;
        this->hide();
        gameOver* gameover1 = new gameOver(this);
        gameover1->show();

    }

    if(score >= 18){
        winning = true;
        this->hide();
        gameOver* gameover1 = new gameOver(this);
        gameover1->show();
    }
}




void MainWindow::on_flipCards_clicked()
{
    if(pressed){
        for(int i =0; i<6; i++){
            for(int j = 0; j<6; j++){
                drawBack(i,j);
            }
        }

        pressed = false;

    }
    else{
        for(int i =0; i<6; i++){
            for(int j = 0; j<6; j++){
                drawFront(i,j);
            }
        }
        pressed = true;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


