//Library and Header Files
#include "booktest.h"
#include "ui_booktest.h"

//Window that displays a qr code for users to book a test

BookTest::BookTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookTest)
{
    ui->setupUi(this);

    //Displays QR Code
    QPixmap img(":/QRC/QR Code/Get tested qr.PNG");
    ui->label->setPixmap(img);
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}

BookTest::~BookTest()
{
    delete ui;
}
