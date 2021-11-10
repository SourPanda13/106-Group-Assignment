#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_pushButton_Signup_clicked()
{
    hide();
    su= new SignUp(this);
    su->show();

}


void MainWindow::on_pushButton_Login_clicked()
{
    hide();
    li= new login(this);
    li->show();
}


