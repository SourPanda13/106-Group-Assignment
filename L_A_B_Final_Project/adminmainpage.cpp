//Library and Header Files
#include "adminmainpage.h"
#include "ui_adminmainpage.h"
#include <mainwindow.h>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include <adminhome.h>
#include <adminaccountdetails.h>
#include <testview.h>
#include <testinput.h>

//Main admin page after selecting a user

Adminmainpage::Adminmainpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adminmainpage)
{
    ui->setupUi(this);


    //Get user data from file and display
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

    //Displays QR code if there is one
    QDir pathDir("./images");
    if(!pathDir.exists())
    {
        QDir().mkdir("./images");
    }

    if(data.at(7)!="")
    {
        QPixmap pixmap(data.at(7));

        ui->label_QRCode->setPixmap(pixmap);
        ui->label_QRCode->setScaledContents(true);
    }


}

Adminmainpage::~Adminmainpage()
{
    delete ui;
}

//Returns to start of application
void Adminmainpage::on_LogOut_2_clicked()
{
    this->hide();
    MainWindow *mw;
    mw = new MainWindow(this);
    mw->show();
}

//Deletes the account
void Adminmainpage::on_GetATest_2_clicked()
{

    //Gets current users email
    QFile currentUserFile("current_user.txt");
    currentUserFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&currentUserFile);

    QString line = in.readLine();
    QStringList data= line.split(",");

    QString account = data.at(0);

    //Uses the email to find the users location in the user file and removes it
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

    //Return to the admin home screen
    AdminHome *ah;
    ah = new AdminHome(this);
    this->hide();
    ah->show();

}

//Displays the editable user information window
void Adminmainpage::on_BookVaccination_clicked()
{
    AdminAccountDetails *aad;
    aad = new AdminAccountDetails(this);
    this->hide();
    aad->show();
}

//Updates user file to show the user has had 1st dose
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


    file += (data_.at(0)+","+data_.at(1)+","+data_.at(2)+","+data_.at(3)+","+data_.at(4)+","+data_.at(5)+","+"1"+","+data_.at(7)+"\n");

    currentUserFile.close();

    QFile currentUserFileOut("current_user.txt");
    currentUserFileOut.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream Out(&currentUserFileOut);

    Out<<(data_.at(0)+","+data_.at(1)+","+data_.at(2)+","+data_.at(3)+","+data_.at(4)+","+data_.at(5)+","+"1"+","+data_.at(7)+"\n");

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

//Updates user file to show the user has had 2nd dose
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


    file += (data_.at(0)+","+data_.at(1)+","+data_.at(2)+","+data_.at(3)+","+data_.at(4)+","+data_.at(5)+","+"2"+","+data_.at(7)+"\n");

    currentUserFile.close();

    QFile currentUserFileOut("current_user.txt");
    currentUserFileOut.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream Out(&currentUserFileOut);

    Out<<(data_.at(0)+","+data_.at(1)+","+data_.at(2)+","+data_.at(3)+","+data_.at(4)+","+data_.at(5)+","+"2"+","+data_.at(7)+"\n");

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

//Displays test view window
void Adminmainpage::on_GetATest_clicked()
{
    TestView *tw;
    tw = new TestView(this);
    tw->show();
}

//Allows admin to add a qr code image and then store the file path to the user file
void Adminmainpage::on_NHIQRCodeDisplay_clicked()
{
    QString imageFilePath = "none.png";

    QString filename;
    filename = QFileDialog::getOpenFileName(this, "Open Image", "./",
                                            "Image Files (*.png *.jpg)");

    if (filename != "")
    {
        int lastSlash = filename.lastIndexOf("/");

        QString shortName = filename.right(filename.size() - lastSlash - 1);

        QFile::copy(filename, "./images/" + shortName);

        QPixmap pixmap("./images/" + shortName);

        ui->label_QRCode->setPixmap(pixmap);
        ui->label_QRCode->setScaledContents(true);

        imageFilePath = "./images/" + shortName;
    }

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


    file += (data_.at(0)+","+data_.at(1)+","+data_.at(2)+","+data_.at(3)+","+data_.at(4)+","+data_.at(5)+","+data_.at(6)+","+imageFilePath+"\n");

    currentUserFile.close();

    QFile currentUserFileOut("current_user.txt");
    currentUserFileOut.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream Out(&currentUserFileOut);

    Out<<(data_.at(0)+","+data_.at(1)+","+data_.at(2)+","+data_.at(3)+","+data_.at(4)+","+data_.at(5)+","+data_.at(6)+","+imageFilePath+"\n");

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
}

//Display window to input user test results
void Adminmainpage::on_GetATest_3_clicked()
{
    TestInput *ti;
    ti = new TestInput(this);
    ti->show();
}

