#include "booktest.h"
#include "ui_booktest.h"

BookTest::BookTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookTest)
{
    ui->setupUi(this);

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
