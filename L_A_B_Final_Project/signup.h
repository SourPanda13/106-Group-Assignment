#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>
#include "login.h"

namespace Ui {
class SignUp;
}

class SignUp : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::SignUp *ui;
    login *li;
};

#endif // SIGNUP_H
