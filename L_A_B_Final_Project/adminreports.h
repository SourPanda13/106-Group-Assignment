#ifndef ADMINREPORTS_H
#define ADMINREPORTS_H

#include <QMainWindow>

namespace Ui {
class AdminReports;
}

class AdminReports : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminReports(QWidget *parent = nullptr);
    ~AdminReports();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AdminReports *ui;
};

#endif // ADMINREPORTS_H
