#ifndef MAINPAGE_H
#define MAINPAGE_H

#include "vaxcertreq.h"
#include "bookvax.h"
#include "booktest.h"
#include "accountdetails.h"
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
private:
    Ui::MainPage *ui;
    VaxCertReq *vcr;
    BookVax *bv;
    BookTest *bt;
    AccountDetails *ad;
};

#endif // MAINPAGE_H

//github testing
