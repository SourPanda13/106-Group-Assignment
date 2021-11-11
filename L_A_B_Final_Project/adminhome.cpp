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
