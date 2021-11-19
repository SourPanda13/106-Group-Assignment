//Library and Header Files
#include "adminhome.h"
#include "ui_adminhome.h"

//Landing page after login as admin

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

//Display user list window
void AdminHome::on_pushButton_clicked()
{
    hide();
    ul = new UserList(this);
    ul->show();
}

//Display reports window
void AdminHome::on_pushButton_2_clicked()
{
    ar = new AdminReports(this);
    this->hide();
    ar->show();
}

