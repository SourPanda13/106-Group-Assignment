#include "adminreports.h"
#include "ui_adminreports.h"
#include <adminhome.h>
#include <QFile>
#include <QTextStream>
#include <QString>

AdminReports::AdminReports(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminReports)
{
    ui->setupUi(this);

    QFile reportFile("reports.txt");
    reportFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&reportFile);

    while (!in.atEnd()) {

        QString line = in.readLine();
        QStringList data= line.split(",");
        ui->comboBox->addItem(data.at(0));
    }

    reportFile.close();
}

AdminReports::~AdminReports()
{
    delete ui;
}

void AdminReports::on_pushButton_clicked()
{
    AdminHome *ah;
    ah = new AdminHome(this);
    this->hide();
    ah->show();
}


void AdminReports::on_pushButton_2_clicked()
{
    QFile reportFile("reports.txt");
    reportFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&reportFile);

    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList data= line.split(",");

        if(data.at(0)==ui->comboBox->itemText(ui->comboBox->currentIndex()))
        {
            ui->textEdit->setText(data.at(1));
            break;
        }

     }
}

