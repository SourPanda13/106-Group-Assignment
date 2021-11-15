#include "adminmainpage.h"
#include "ui_adminmainpage.h"
#include <mainwindow.h>
#include <QFile>
#include <QTextStream>
#include <QString>


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

