#ifndef ADMINHOME_H
#define ADMINHOME_H

#include <QDialog>

namespace Ui {
class AdminHome;
}

class AdminHome : public QDialog
{
    Q_OBJECT

public:
    explicit AdminHome(QWidget *parent = nullptr);
    ~AdminHome();

private:
    Ui::AdminHome *ui;
};

#endif // ADMINHOME_H
