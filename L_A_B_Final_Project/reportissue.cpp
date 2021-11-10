#include "reportissue.h"
#include "ui_reportissue.h"

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



