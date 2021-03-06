#ifndef MAINPAGE_H
#define MAINPAGE_H

#include "vaxcertreq.h"
#include "bookvax.h"
#include "booktest.h"
#include "accountdetails.h"
#include "reportissue.h"
#include "testinput.h"
#include "testview.h"
#include "userqrcode.h"
#include <QMainWindow>

namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();

private slots:
    void on_RequestDigitalVaccineCertificate_clicked();

    void on_BookVaccination_clicked();

    void on_GetATest_clicked();

    void on_LogOut_clicked();

     void on_ViewAccountDetails_clicked();
     void on_RequestDigitalVaccineCertificate_2_clicked();

     void on_RequestDigitalVaccineCertificate_3_clicked();

     void on_NHIQRCodeDisplay_clicked();

private:
    Ui::MainPage *ui;
    VaxCertReq *vcr;
    BookVax *bv;
    BookTest *bt;
    AccountDetails *ad;
    ReportIssue *ri;
    TestInput *ti;
    TestView *tv;
    UserQRCode *qr;
};

#endif // MAINPAGE_H

//github testing
