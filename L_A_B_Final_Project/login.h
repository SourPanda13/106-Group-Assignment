#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QString>
#include "mainpage.h"
#include "admin_main.h"
#include "adminmainpage.h"

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;
    MainPage *mp;
    Adminmainpage *am;
};

class User
{
    QString username;
    QString password;
    QString name;
    QString dob;
    QString id;
    QString nhi;
    int no_of_vax;
public:
    User(QString, QString, QString, QString, QString, QString, int);
};

#endif // LOGIN_H
