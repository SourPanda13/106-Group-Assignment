#ifndef REPORTISSUE_H
#define REPORTISSUE_H

#include <QDialog>

namespace Ui {
class ReportIssue;
}

class ReportIssue : public QDialog
{
    Q_OBJECT

public:
    explicit ReportIssue(QWidget *parent = nullptr);
    ~ReportIssue();


private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_submit_clicked();

private:
    Ui::ReportIssue *ui;
};

#endif // REPORTISSUE_H
