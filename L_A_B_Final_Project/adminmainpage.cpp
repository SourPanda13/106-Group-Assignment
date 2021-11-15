#include "adminmainpage.h"
#include "ui_adminmainpage.h"
#include <mainwindow.h>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#include <adminhome.h>


Adminmainpage::Adminmainpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adminmainpage)
{
    ui->setupUi(this);

    QFile userFile("current_user.txt");
    userFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&userFile);

    QString line = in.readLine();
    QStringList data= line.split(",");

    if(data.at(6)=="2")
    {
        ui->Dose1Confirmation->setText("Confirmed");
        ui->Dose2Confirmation->setText("Confirmed");
    }
    else if (data.at(6)=="1")
    {
        ui->Dose1Confirmation->setText("Confirmed");
        ui->Dose2Confirmation->setText("Unconfirmed");
    }
    else
    {
        ui->Dose1Confirmation->setText("Unconfirmed");
        ui->Dose2Confirmation->setText("Unconfirmed");
    }
}

Adminmainpage::~Adminmainpage()
{
    delete ui;
}

void Adminmainpage::on_LogOut_2_clicked()
{
    this->hide();
    MainWindow *mw;
    mw = new MainWindow(this);
    mw->show();
}


void Adminmainpage::on_GetATest_2_clicked()
{

    QFile currentUserFile("current_user.txt");
    currentUserFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&currentUserFile);

    QString line = in.readLine();
    QStringList data= line.split(",");

    QString account = data.at(0);

    QFile userFile("user.txt");
    if(userFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QString s;
        QTextStream t(&userFile);
        while(!t.atEnd())
        {
            QString line = t.readLine();
            if(!line.contains(account))
                s.append(line + "\n");
        }
        userFile.resize(0);
        t << s;
        userFile.close();
    }

    QMessageBox::information(this,"Deleted","This account has been successfully deleted.");

    AdminHome *ah;
    ah = new AdminHome(this);
    this->hide();
    ah->show();

}

