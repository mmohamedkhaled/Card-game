#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>
#include "mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>

namespace Ui {
class gameOver;
}

class gameOver : public QDialog
{
    Q_OBJECT

public:
    gameOver(MainWindow* mainView);
    QGraphicsScene* scene;
    QGraphicsView* view;
    ~gameOver();

private:
    Ui::gameOver *ui;
};

#endif // GAMEOVER_H
