//Library and Header Files
#include "adminaccountdetails.h"
#include "ui_adminaccountdetails.h"
#include <adminmainpage.h>

#include <QTextStream>
#include <QFile>
#include <QMessageBox>

//Window that displays user information to admin with ability to edit

AdminAccountDetails::AdminAccountDetails(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminAccountDetails)
{
    ui->setupUi(this);

    //Get user info from file
    QFile userFile("current_user.txt");
    userFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&userFile);

    QString line = in.readLine();
    QStringList data= line.split(",");

    //Display info from file
    ui->lineEdit_Name->setText(data.at(2));
    ui->lineEdit_NHI->setText(data.at(5));
    ui->lineEdit_Email->setText(data.at(0));
}

AdminAccountDetails::~AdminAccountDetails()
{
    delete ui;
}

//Close window and return to main admin page
void AdminAccountDetails::on_pushButton_back_clicked()
{
    Adminmainpage *am;
    am = new Adminmainpage(this);
    this->hide();
    am->show();


}

//Saves changes to user file
void AdminAccountDetails::on_pushButton_save_clicked()
{
    //Get data from files
    QFile currentUserFile("current_user.txt");
    currentUserFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&currentUserFile);

    QString line_ = in.readLine();
    QStringList data_= line_.split(",");

    QString email = data_.at(0);

    QFile userFileIn("user.txt");
    userFileIn.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream FileIn(&userFileIn);


    //Write data into a QString
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

    //Add the changes to the QString
    file += (ui->lineEdit_Email->text()+","+data_.at(1)+","+ui->lineEdit_Name->text()+","+data_.at(3)+","+data_.at(4)+","+ui->lineEdit_NHI->text()+","+data_.at(6)+","+data_.at(7)+"\n");

    currentUserFile.close();

    QFile currentUserFileOut("current_user.txt");
    currentUserFileOut.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream Out(&currentUserFileOut);

    //Add the changes to the current user file
    Out<<(ui->lineEdit_Email->text()+","+data_.at(1)+","+ui->lineEdit_Name->text()+","+data_.at(3)+","+data_.at(4)+","+ui->lineEdit_NHI->text()+","+data_.at(6)+","+data_.at(7)+"\n");

    int j = 0;

    //Add the rest of the file to the QString
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

    //Put the QString back into the file
    FileOut<<file;

    QMessageBox::information(this, "Complete" , "Data has been saved");
}

