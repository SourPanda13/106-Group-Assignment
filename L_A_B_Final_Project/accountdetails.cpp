#include "accountdetails.h"
#include "ui_accountdetails.h"

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>


AccountDetails::AccountDetails(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountDetails)
{
    ui->setupUi(this);

    QFile userFile("current_user.txt");
    userFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&userFile);

    QString line = in.readLine();
    QStringList data= line.split(",");

    ui->NameLabel->setText(data.at(2));
    ui->NHILabel->setText(data.at(5));
    ui->EmailLabel->setText(data.at(0));


}

AccountDetails::~AccountDetails()
{
    delete ui;
}

void AccountDetails::on_pushButton_clicked()
{
    hide();
}
