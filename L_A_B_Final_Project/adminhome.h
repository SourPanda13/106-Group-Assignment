#ifndef ADMINHOME_H
#define ADMINHOME_H

#include <QDialog>
#include <userlist.h>

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

private:
    Ui::AdminHome *ui;
    UserList *ul;
};

#endif // ADMINHOME_H
