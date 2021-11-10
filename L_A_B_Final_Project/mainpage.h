#ifndef MAINPAGE_H
#define MAINPAGE_H

#include "vaxcertreq.h"
#include "bookvax.h"
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

private:
    Ui::MainPage *ui;
    VaxCertReq *vcr;
    BookVax *bv;
};

#endif // MAINPAGE_H
