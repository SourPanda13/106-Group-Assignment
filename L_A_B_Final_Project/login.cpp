#include "login.h"
#include "ui_login.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>

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

User::User(QString username,QString pass, QString name, QString dob, QString id, QString nhi, int vax_no)
{
    this->username=username;
    this->password=pass;
    this->name=name;
    this->dob=dob;
    this->id=id;
    this->nhi=nhi;
    this->no_of_vax=vax_no;
}


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

        if(username=="admin123" && password == "login321")
        {
            QMessageBox::information(this,"Success","Succesfully logged in as Admin");
            flag = true;
            hide();
            am = new Adminmainpage(this);
            am->show();
            break;
        }
        else if(username==data.at(0) && password==data.at(1))
        {
            User user(QString (data.at(0)),QString (data.at(1)),QString (data.at(2)),QString (data.at(3)),QString (data.at(4)),QString (data.at(5)), data.at(6).toInt());
            QMessageBox::information(this,"Success","Succesfully logged in");

            hide();
            mp= new MainPage(this);
            mp->show();

            flag = true;
            break;
        }
     }
    if (!flag)
    {
        QMessageBox::information(this,"Login Failed","Incorrect Username or Password");
    }

}

