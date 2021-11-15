#include "adminhome.h"
#include "ui_adminhome.h"

AdminHome::AdminHome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminHome)
{
    ui->setupUi(this);
}

AdminHome::~AdminHome()
{
    delete ui;
}

void AdminHome::on_pushButton_clicked()
{
    hide();
    ul = new UserList(this);
    ul->show();
}


void AdminHome::on_pushButton_2_clicked()
{
    ar = new AdminReports(this);
    this->hide();
    ar->show();
}

