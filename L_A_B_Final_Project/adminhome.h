#ifndef ADMINHOME_H
#define ADMINHOME_H

#include <QDialog>
#include <userlist.h>
#include <adminreports.h>

namespace Ui {
class AdminHome;
}

class AdminHome : public QDialog
{
    Q_OBJECT

public:
    explicit AdminHome(QWidget *parent = nullptr);
    ~AdminHome();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AdminHome *ui;
    UserList *ul;
    AdminReports *ar;
};

#endif // ADMINHOME_H
