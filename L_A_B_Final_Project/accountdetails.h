#ifndef ACCOUNTDETAILS_H
#define ACCOUNTDETAILS_H

#include <QWidget>

namespace Ui {
class AccountDetails;
}

class AccountDetails : public QWidget
{
    Q_OBJECT

public:
    explicit AccountDetails(QWidget *parent = nullptr);
    ~AccountDetails();
private slots:
    void on_pushButton_clicked();
private:
    Ui::AccountDetails *ui;
};

#endif // ACCOUNTDETAILS_H
