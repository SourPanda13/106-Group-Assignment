#include "adminmainpage.h"
#include "ui_adminmainpage.h"

Adminmainpage::Adminmainpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adminmainpage)
{
    ui->setupUi(this);
}

Adminmainpage::~Adminmainpage()
{
    delete ui;
}
