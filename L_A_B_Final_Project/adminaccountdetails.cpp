#include "adminaccountdetails.h"
#include "ui_adminaccountdetails.h"
#include <adminmainpage.h>

#include <QTextStream>
#include <QFile>
#include <QMessageBox>

AdminAccountDetails::AdminAccountDetails(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminAccountDetails)
{
    ui->setupUi(this);

    QFile userFile("current_user.txt");
    userFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&userFile);

    QString line = in.readLine();
    QStringList data= line.split(",");

    ui->lineEdit_Name->setText(data.at(2));
    ui->lineEdit_NHI->setText(data.at(5));
    ui->lineEdit_Email->setText(data.at(0));
}

AdminAccountDetails::~AdminAccountDetails()
{
    delete ui;
}

void AdminAccountDetails::on_pushButton_back_clicked()
{
    Adminmainpage *am;
    am = new Adminmainpage(this);
    this->hide();
    am->show();


}


void AdminAccountDetails::on_pushButton_save_clicked()
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


    file += (ui->lineEdit_Email->text()+","+data_.at(1)+","+ui->lineEdit_Name->text()+","+data_.at(3)+","+data_.at(4)+","+ui->lineEdit_NHI->text()+","+data_.at(6)+"\n");

    currentUserFile.close();

    QFile currentUserFileOut("current_user.txt");
    currentUserFileOut.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream Out(&currentUserFileOut);

    Out<<(ui->lineEdit_Email->text()+","+data_.at(1)+","+ui->lineEdit_Name->text()+","+data_.at(3)+","+data_.at(4)+","+ui->lineEdit_NHI->text()+","+data_.at(6)+"\n");

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

    QMessageBox::information(this, "Complete" , "Data has been saved");
}

