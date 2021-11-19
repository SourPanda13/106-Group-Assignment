//Library and Header Files
#include "vaxcertreq.h"
#include "ui_vaxcertreq.h"

//Window that displays a simple message

VaxCertReq::VaxCertReq(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VaxCertReq)
{
    ui->setupUi(this);
}

VaxCertReq::~VaxCertReq()
{
    delete ui;
}
