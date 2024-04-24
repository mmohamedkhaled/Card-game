#ifndef LOGIN_H
#define LOGIN_H
#include <QMap>
#include <QString>

#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_loginButton_clicked();

    void on_cancel_clicked();

private:
    Ui::login *ui;
    QString     users[5] = {"admin","admin1","admin2","admin3","admin4"};
    QString passwords[5] ={"admin","admin1","admin2","admin3","admin4"};
    bool match;

};

#endif // LOGIN_H
