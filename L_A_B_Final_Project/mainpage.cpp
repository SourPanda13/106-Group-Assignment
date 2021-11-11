#include "mainpage.h"
#include "ui_mainpage.h"
#include "login.cpp"

MainPage::MainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);



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

