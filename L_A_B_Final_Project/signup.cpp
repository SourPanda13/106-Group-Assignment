//Library and Header Files
#include "signup.h"
#include "ui_signup.h"

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>

//Window for users to enter their information and create an account

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


//Go to login screen
void SignUp::on_pushButton_2_clicked()
{
    hide();
    li= new login(this);
    li->show();
}

//If there are no errors takes inputted information and adds it to the user file
void SignUp::on_pushButton_clicked()
{
    if(ui->checkBox_tc->isChecked())
    {
        QString username = ui->lineEdit_Username->text();
        QString password= ui->lineEdit_Password->text();
        QString name = ui->lineEdit_Name->text();
        QString dob = ui->lineEdit_DOB->text();
        QString id = ui->lineEdit_ID->text();
        QString nhi = ui->lineEdit_NHI->text();

        QFile userFileIn("user.txt");
        userFileIn.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&userFileIn);

        bool flag = false;

        while(!in.atEnd())
        {
            QString line = in.readLine();
            QStringList data= line.split(",");

            if (data.at(0) == username)
            {
                flag = true;
            }
        }

        if(flag)
        {
            QMessageBox::warning(this,"Error","There is already an account registered with this email address");
        }
        else
        {
            QFile userFile("user.txt");
            userFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
            QTextStream out(&userFile);

            out<<username<<","<<password<<","<<name<<","<<dob<<","<<id<<","<<nhi<<",";
            if(ui->checkBox_seconddose->isChecked())
            {
                out<<2<<","<<""<<Qt::endl;
            }
            else if (ui->checkBox_firstdose->isChecked())
            {
                out<<1<<","<<""<<Qt::endl;
            }

            else
            {
                out<<0<<","<<""<<Qt::endl;
            }

            QMessageBox::information(this,"Account created","Your account has been created");

            hide();
            li= new login(this);
            li->show();
        }

    }
    else
    {
        QMessageBox::information(this,"Error","You must accept the terms and conditions");
    }
}

