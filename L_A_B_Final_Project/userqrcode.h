#ifndef USERQRCODE_H
#define USERQRCODE_H

#include <QDialog>

namespace Ui {
class UserQRCode;
}

class UserQRCode : public QDialog
{
    Q_OBJECT

public:
    explicit UserQRCode(QWidget *parent = nullptr);
    ~UserQRCode();

private:
    Ui::UserQRCode *ui;
};

#endif // USERQRCODE_H
