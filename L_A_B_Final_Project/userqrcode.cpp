#include "userqrcode.h"
#include "ui_userqrcode.h"
#include <QFile>
#include <QDir>

UserQRCode::UserQRCode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserQRCode)
{
    ui->setupUi(this);

    QFile userFile("current_user.txt");
    userFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&userFile);

    QString line = in.readLine();
    QStringList data= line.split(",");

    QDir pathDir("./images");
    if(!pathDir.exists())
    {
        QDir().mkdir("./images");
    }

    if(data.at(7)!="")
    {
        QPixmap pixmap(data.at(7));

        ui->label->setPixmap(pixmap);
        ui->label->setScaledContents(true);
    }
    else
    {
        ui->label_2->setText("No QR Code Found");
    }
}

UserQRCode::~UserQRCode()
{
    delete ui;
}
