#ifndef ADMINMAINPAGE_H
#define ADMINMAINPAGE_H

#include <QDialog>

namespace Ui {
class Adminmainpage;
}

class Adminmainpage : public QDialog
{
    Q_OBJECT

public:
    explicit Adminmainpage(QWidget *parent = nullptr);
    ~Adminmainpage();

private slots:
    void on_LogOut_2_clicked();

    void on_GetATest_2_clicked();

    void on_BookVaccination_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Adminmainpage *ui;
};

#endif // ADMINMAINPAGE_H
