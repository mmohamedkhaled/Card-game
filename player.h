#ifndef PLAYER_H
#define PLAYER_H
#include "mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include <QTime>


class player :public QGraphicsPixmapItem , public QObject
{
    int colIndex;
    int rowIndex;
    bool visible = 1;
    card * pre;
    card * pre2;
    QGraphicsPixmapItem* preImage;
    QGraphicsPixmapItem* pre2Image;
    int pre2Row;
    int pre2Col;
    int preRow;
    int preCol;



public slots:
    void keyPressEvent(QKeyEvent* event);
public:
    player(MainWindow* mainView);
    MainWindow* mainWindow;
    QTime* timer;
};

#endif // PLAYER_H
