#ifndef TESTVIEW_H
#define TESTVIEW_H

#include <QDialog>

namespace Ui {
class TestView;
}

class TestView : public QDialog
{
    Q_OBJECT

public:
    explicit TestView(QWidget *parent = nullptr);
    ~TestView();

private:
    Ui::TestView *ui;
};

#endif // TestView_H
