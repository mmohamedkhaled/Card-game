#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->loginButton->setStyleSheet("background-color-black");
    ui->cancel->setStyleSheet("background-color-black");
    match = false;

}

login::~login()
{
    delete ui;
}

void login::on_loginButton_clicked()
{
    QString username = ui->userName->text();
    QString password = ui->passWord->text();

    for(int i =0; i <5; i++){
        if(username == users[i] && password == passwords[i]){
            match = true;

        }
    }

    if(match == true){
        this->hide();
        MainWindow* mainView = new MainWindow;
        mainView->show();

    }




}


void login::on_cancel_clicked()
{
    this->hide();

}

