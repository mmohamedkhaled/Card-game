#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "card.h"
#include <QVector>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsTextItem>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QGraphicsScene* scene;
    QGraphicsView* view;
    QGraphicsPixmapItem cards[6][6];
    Ui::MainWindow *ui;
    QVector <QVector<card*>> grid;
    int rows;
    int cols;
    void drawFront(int i, int j);
    void drawBack(int i, int j);
    bool pressed;
    void drawPlayer(int rows, int cols);
    void isGameOver();
    int openings;
    int score;
    bool winning;
    QGraphicsTextItem* lable1;
    QGraphicsTextItem* lable2;


private slots:
    void on_flipCards_clicked();

private:


};
#endif // MAINWINDOW_H
