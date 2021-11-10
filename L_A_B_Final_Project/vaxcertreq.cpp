#include "vaxcertreq.h"
#include "ui_vaxcertreq.h"

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
