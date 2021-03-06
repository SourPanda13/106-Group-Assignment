#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QString>
#include "mainpage.h"
#include "adminmainpage.h"
#include "adminhome.h"

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
    AdminHome *ah;
};


#endif // LOGIN_H
