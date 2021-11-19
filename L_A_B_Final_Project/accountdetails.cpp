//Library and Header Files
#include "accountdetails.h"
#include "ui_accountdetails.h"

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>

//Window that displays users information

AccountDetails::AccountDetails(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountDetails)
{
    ui->setupUi(this);

    //Open file to get user info
    QFile userFile("current_user.txt");
    userFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&userFile);

    QString line = in.readLine();
    QStringList data= line.split(",");

    //Display user info from file
    ui->NameLabel->setText(data.at(2));
    ui->NHILabel->setText(data.at(5));
    ui->EmailLabel->setText(data.at(0));


}

AccountDetails::~AccountDetails()
{
    delete ui;
}

//Close window button
void AccountDetails::on_pushButton_clicked()
{
    hide();
}
