#include "signup.h"
#include "ui_signup.h"

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>

SignUp::SignUp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}



void SignUp::on_pushButton_2_clicked()
{
    hide();
    li= new login(this);
    li->show();
}


void SignUp::on_pushButton_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password= ui->lineEdit_Password->text();
    QString name = ui->lineEdit_Name->text();
    QString dob = ui->lineEdit_DOB->text();
    QString id = ui->lineEdit_ID->text();
    QString nhi = ui->lineEdit_NHI->text();


    QFile userFile("user.txt");
    userFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    QTextStream out(&userFile);

    out<<username<<","<<password<<","<<name<<","<<dob<<","<<id<<","<<nhi<<",";
    if (ui->checkBox_firstdose->isChecked())
    {
        out<<1<<Qt::endl;
    }
    else if(ui->checkBox_seconddose->isChecked())
    {
        out<<2<<Qt::endl;
    }
    else
    {
        out<<0<<Qt::endl;
    }

    QMessageBox::information(this,"Account created","Your account has been created");

    hide();
    li= new login(this);
    li->show();
}

