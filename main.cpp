#include "mainwindow.h"
#include "gameboard.h"
#include "card.h"
#include "login.h"
#include <QGraphicsPixmapItem>

#include <QApplication>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login loginn;
    loginn.show();
    return a.exec();
}
