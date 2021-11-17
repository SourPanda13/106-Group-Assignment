#ifndef TESTINPUT_H
#define TESTINPUT_H

#include <QDialog>

namespace Ui {
class TestInput;
}

class TestInput : public QDialog
{
    Q_OBJECT

public:
    explicit TestInput(QWidget *parent = nullptr);
    ~TestInput();

private slots:

    void on_buttonBox_accepted();

private:
    Ui::TestInput *ui;
};

#endif // TESTINPUT_H
