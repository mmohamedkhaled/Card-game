#include "gameover.h"
#include "ui_gameover.h"
#include "QGraphicsTextItem"
#include "mainwindow.h"

gameOver::gameOver(MainWindow* mainView)    :
     ui(new Ui::gameOver)

{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    view = new QGraphicsView;
    view->setScene(scene);
    ui->graphicsView->setScene(scene);

    QGraphicsTextItem * GameState = new QGraphicsTextItem;
    GameState->setFont(QFont("times",26));
    GameState->setPos(300,400);

    QGraphicsTextItem * score = new QGraphicsTextItem;
    score->setFont(QFont("times",16));
    score->setPos(200,700);
    score->setDefaultTextColor(Qt::white);
    score->setPlainText("Score: "+ QString::number(mainView->score));
    scene->addItem(score);

    QGraphicsTextItem * openings = new QGraphicsTextItem;
    openings->setFont(QFont("times",16));
    openings->setPos(500,700);
    openings->setDefaultTextColor(Qt::white);
    openings->setPlainText("Openings: " + QString::number(mainView->openings));
    scene->addItem(openings);






    if(mainView->winning == true){
        GameState->setDefaultTextColor(Qt::green);
        GameState->setPlainText("You won!");
    }
    else{
        GameState->setDefaultTextColor(Qt::red);
        GameState->setPlainText("You Lose!");

    }

    scene->addItem(GameState);
    ui->graphicsView->show();



}

gameOver::~gameOver()
{
    delete ui;
}
