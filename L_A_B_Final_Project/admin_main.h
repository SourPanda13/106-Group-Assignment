#ifndef ADMIN_MAIN_H
#define ADMIN_MAIN_H

#include <QMainWindow>

namespace Ui {
class Admin_Main;
}

class Admin_Main : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin_Main(QWidget *parent = nullptr);
    ~Admin_Main();

private slots:

private:
    Ui::Admin_Main *ui;
};

#endif // ADMIN_MAIN_H
