#ifndef USERLIST_H
#define USERLIST_H

#include <QDialog>
#include "adminmainpage.h"

namespace Ui {
class UserList;
}

class UserList : public QDialog
{
    Q_OBJECT

public:
    explicit UserList(QWidget *parent = nullptr);
    ~UserList();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UserList *ui;
    Adminmainpage *amp;
};

#endif // USERLIST_H
