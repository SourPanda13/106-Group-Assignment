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


private:
    Ui::ReportIssue *ui;
};

#endif // REPORTISSUE_H
