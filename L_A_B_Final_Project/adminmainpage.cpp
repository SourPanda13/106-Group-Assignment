#include "adminmainpage.h"
#include "ui_adminmainpage.h"
#include <mainwindow.h>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#include <adminhome.h>
#include <adminaccountdetails.h>


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
        ui->pushButton->hide();
        ui->pushButton_2->hide();
    }
    else if (data.at(6)=="1")
    {
        ui->Dose1Confirmation->setText("Confirmed");
        ui->Dose2Confirmation->setText("Unconfirmed");
        ui->pushButton->hide();
    }
    else
    {
        ui->Dose1Confirmation->setText("Unconfirmed");
        ui->Dose2Confirmation->setText("Unconfirmed");
        ui->pushButton_2->hide();
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


void Adminmainpage::on_BookVaccination_clicked()
{
    AdminAccountDetails *aad;
    aad = new AdminAccountDetails(this);
    this->hide();
    aad->show();
}


void Adminmainpage::on_pushButton_clicked()
{
    QFile currentUserFile("current_user.txt");
    currentUserFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&currentUserFile);

    QString line_ = in.readLine();
    QStringList data_= line_.split(",");

    QString email = data_.at(0);

    QFile userFileIn("user.txt");
    userFileIn.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream FileIn(&userFileIn);


    int i = 0;
    QString file = "";

    while(!FileIn.atEnd())
    {

        QString line = FileIn.readLine();
        QStringList data= line.split(",");


        if(data.at(0)==email)
        {
            break;
        }

        file += line;
        file += "\n";

        i++;
    }


    file += (data_.at(0)+","+data_.at(1)+","+data_.at(2)+","+data_.at(3)+","+data_.at(4)+","+data_.at(5)+","+"1"+"\n");

    currentUserFile.close();

    QFile currentUserFileOut("current_user.txt");
    currentUserFileOut.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream Out(&currentUserFileOut);

    Out<<(data_.at(0)+","+data_.at(1)+","+data_.at(2)+","+data_.at(3)+","+data_.at(4)+","+data_.at(5)+","+"1"+"\n");

    int j = 0;


    while(!FileIn.atEnd())
    {

        QString line = FileIn.readLine();

        j++;

        if(j > 0)
        {
            file += line;
            file += "\n";
        }

    }

    userFileIn.close();

    QFile userFileOut("user.txt");
    userFileOut.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream FileOut(&userFileOut);

    FileOut<<file;
    ui->Dose1Confirmation->setText("Confirmed");
    ui->Dose2Confirmation->setText("Unconfirmed");
    ui->pushButton->hide();

    QMessageBox::information(this,"Complete","Vaccine status has been updated");
}


void Adminmainpage::on_pushButton_2_clicked()
{
    QFile currentUserFile("current_user.txt");
    currentUserFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&currentUserFile);

    QString line_ = in.readLine();
    QStringList data_= line_.split(",");

    QString email = data_.at(0);

    QFile userFileIn("user.txt");
    userFileIn.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream FileIn(&userFileIn);


    int i = 0;
    QString file = "";

    while(!FileIn.atEnd())
    {

        QString line = FileIn.readLine();
        QStringList data= line.split(",");


        if(data.at(0)==email)
        {
            break;
        }

        file += line;
        file += "\n";

        i++;
    }


    file += (data_.at(0)+","+data_.at(1)+","+data_.at(2)+","+data_.at(3)+","+data_.at(4)+","+data_.at(5)+","+"2"+"\n");

    currentUserFile.close();

    QFile currentUserFileOut("current_user.txt");
    currentUserFileOut.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream Out(&currentUserFileOut);

    Out<<(data_.at(0)+","+data_.at(1)+","+data_.at(2)+","+data_.at(3)+","+data_.at(4)+","+data_.at(5)+","+"2"+"\n");

    int j = 0;


    while(!FileIn.atEnd())
    {

        QString line = FileIn.readLine();

        j++;

        if(j > 0)
        {
            file += line;
            file += "\n";
        }

    }

    userFileIn.close();

    QFile userFileOut("user.txt");
    userFileOut.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream FileOut(&userFileOut);

    FileOut<<file;
    ui->Dose1Confirmation->setText("Confirmed");
    ui->Dose2Confirmation->setText("Confirmed");
    ui->pushButton_2->hide();

    QMessageBox::information(this,"Complete","Vaccine status has been updated");
}
