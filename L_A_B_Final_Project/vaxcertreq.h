#ifndef VAXCERTREQ_H
#define VAXCERTREQ_H

#include <QDialog>

namespace Ui {
class VaxCertReq;
}

class VaxCertReq : public QDialog
{
    Q_OBJECT

public:
    explicit VaxCertReq(QWidget *parent = nullptr);
    ~VaxCertReq();

private:
    Ui::VaxCertReq *ui;
};

#endif // VAXCERTREQ_H
