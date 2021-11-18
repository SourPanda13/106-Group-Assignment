#include "mainpage.h"
#include "ui_mainpage.h"
#include <mainwindow.h>

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>


MainPage::MainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainPage)
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

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::on_BookVaccination_clicked()
{
    bv = new BookVax(this);
    bv-> show();
}

void MainPage::on_RequestDigitalVaccineCertificate_clicked()
{
    vcr = new VaxCertReq(this);
    vcr-> show();
}


void MainPage::on_GetATest_clicked()
{
    bt = new BookTest(this);
    bt-> show();
}


void MainPage::on_LogOut_clicked()
{
    this->hide();
    MainWindow *mw;
    mw = new MainWindow();
    mw->show();
}

void MainPage::on_ViewAccountDetails_clicked()
{
   ad= new AccountDetails(this);
   ad->show();

}

void MainPage::on_RequestDigitalVaccineCertificate_2_clicked()
{
    ri = new ReportIssue(this);
    this->hide();
    ri->show();
}


void MainPage::on_RequestDigitalVaccineCertificate_3_clicked()
{
    tv = new TestView(this);
    tv->show();
}


void MainPage::on_NHIQRCodeDisplay_clicked()
{
    qr = new UserQRCode(this);
    qr->show();
}

