//Library and Header Files
#include "mainwindow.h"
#include "ui_mainwindow.h"

//The initial landing screen

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Opens window for users to sign up
void MainWindow::on_pushButton_Signup_clicked()
{
    hide();
    su= new SignUp(this);
    su->show();

}

//Opens window for users to log in
void MainWindow::on_pushButton_Login_clicked()
{
    hide();
    li= new login(this);
    li->show();
}


