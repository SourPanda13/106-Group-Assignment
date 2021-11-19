//Library and Header Files
#include "contactus.h"
#include "ui_contactus.h"

//Window that displays contact information

ContactUs::ContactUs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactUs)
{
    ui->setupUi(this);
}

ContactUs::~ContactUs()
{
    delete ui;
}
