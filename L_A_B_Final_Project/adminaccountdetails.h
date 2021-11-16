#ifndef ADMINACCOUNTDETAILS_H
#define ADMINACCOUNTDETAILS_H

#include <QMainWindow>

namespace Ui {
class AdminAccountDetails;
}

class AdminAccountDetails : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminAccountDetails(QWidget *parent = nullptr);
    ~AdminAccountDetails();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_save_clicked();

private:
    Ui::AdminAccountDetails *ui;
};

#endif // ADMINACCOUNTDETAILS_H
