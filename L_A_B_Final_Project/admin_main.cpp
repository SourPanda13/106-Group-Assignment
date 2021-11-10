#include "admin_main.h"
#include "ui_admin_main.h"

Admin_Main::Admin_Main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin_Main)
{
    ui->setupUi(this);
}

Admin_Main::~Admin_Main()
{
    delete ui;
}


