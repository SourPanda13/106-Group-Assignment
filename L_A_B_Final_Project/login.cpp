//Library and Header Files
#include "login.h"
#include "ui_login.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>

//Window that allows users and admin to login to their accounts

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

//Gets username/email and password as inputs and checks the user file for any matches
void login::on_pushButton_clicked()
{


    QString username = ui->lineEdit->text();
    QString password= ui->lineEdit_7->text();

    QFile userFile("user.txt");
    userFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&userFile);

    bool flag = false;

    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList data= line.split(",");

        //If the admin login credentials are inputted then it opens the admin home screen
        if(username=="admin123" && password == "login321")
        {
            QMessageBox::information(this,"Success","Succesfully logged in as Admin");
            flag = true;
            hide();
            ah = new AdminHome(this);
            ah->show();
            break;
        }
        //If a match is found then it adds their information to the current user file and opens the users main page
        else if(username==data.at(0) && password==data.at(1))
        {
            QMessageBox::information(this,"Success","Succesfully logged in");
            
            QFile userFile("current_user.txt");
            userFile.open(QIODevice::WriteOnly | QIODevice::Text);
            QTextStream out(&userFile);
                   
            out<<data.at(0)<<","<<data.at(1)<<","<<data.at(2)<<","<<data.at(3)<<","<<data.at(4)<<","<<data.at(5)<<","<<data.at(6)<<","<<data.at(7)<<Qt::endl;

            hide();
            mp= new MainPage(this);
            mp->show();

            flag = true;
            break;
        }
     }
    //Failed login
    if (!flag)
    {
        QMessageBox::critical(this,"Login Failed","Incorrect Username or Password");
    }

}

