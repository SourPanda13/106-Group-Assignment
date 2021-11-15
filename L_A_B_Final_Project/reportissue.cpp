#include "reportissue.h"
#include "ui_reportissue.h"
#include <mainpage.h>
#include <QFile>
#include <QMessageBox>

ReportIssue::ReportIssue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportIssue)
{
    ui->setupUi(this);
}

ReportIssue::~ReportIssue()
{
    delete ui;
}




void ReportIssue::on_pushButton_back_clicked()
{
    MainPage *mp;
    mp= new MainPage(this);
    this->hide();
    mp->show();
}


void ReportIssue::on_pushButton_submit_clicked()
{

    QFile currentUserFile("current_user.txt");
    currentUserFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&currentUserFile);

    QFile reportFile("reports.txt");
    reportFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    QTextStream out(&reportFile);

    QString line = in.readLine();
    QStringList data= line.split(",");

    QString issue = ui->plainTextEdit->toPlainText();

    issue.replace('\n', ' ');

    out<<data.at(0)<< "," << issue<<Qt::endl;

    QMessageBox::information(this,"Complete","The report has been sent to an admin");

    MainPage *mp;
    mp= new MainPage(this);
    this->hide();
    mp->show();

}

