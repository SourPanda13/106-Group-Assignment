#include "bookvax.h"
#include "ui_bookvax.h"

BookVax::BookVax(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookVax)
{
    ui->setupUi(this);

    QPixmap img(":/QRC/QR Code/Book vax.png");
    ui->label->setPixmap(img);
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));

    //QImage *bookvax = new QImage(":/QRC/QR Code/Book vax.png");
}

BookVax::~BookVax()
{
    delete ui;
}
