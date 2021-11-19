//Library and Header Files
#include "mainpage.h"
#include "ui_mainpage.h"
#include <mainwindow.h>

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>

//The main user home screen after users login in
MainPage::MainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);

    //Displays vaccine doses
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

MainPage::~MainPage()
{
    delete ui;
}

//Opens book vax window
void MainPage::on_BookVaccination_clicked()
{
    bv = new BookVax(this);
    bv-> show();
}

//Opens vax certificate window
void MainPage::on_RequestDigitalVaccineCertificate_clicked()
{
    vcr = new VaxCertReq(this);
    vcr-> show();
}

//Opens book test window
void MainPage::on_GetATest_clicked()
{
    bt = new BookTest(this);
    bt-> show();
}

//Returns to the landing page
void MainPage::on_LogOut_clicked()
{
    this->hide();
    MainWindow *mw;
    mw = new MainWindow();
    mw->show();
}

//Opens window to display user information
void MainPage::on_ViewAccountDetails_clicked()
{
   ad= new AccountDetails(this);
   ad->show();

}

//Opens window for users to input issue reports
void MainPage::on_RequestDigitalVaccineCertificate_2_clicked()
{
    ri = new ReportIssue(this);
    this->hide();
    ri->show();
}

//Opens window for users to view their test results
void MainPage::on_RequestDigitalVaccineCertificate_3_clicked()
{
    tv = new TestView(this);
    tv->show();
}

//Opens window for users to view their QR Code
void MainPage::on_NHIQRCodeDisplay_clicked()
{
    qr = new UserQRCode(this);
    qr->show();
}

