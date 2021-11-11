#ifndef BOOKTEST_H
#define BOOKTEST_H

#include <QDialog>

namespace Ui {
class BookTest;
}

class BookTest : public QDialog
{
    Q_OBJECT

public:
    explicit BookTest(QWidget *parent = nullptr);
    ~BookTest();

private:
    Ui::BookTest *ui;
};

#endif // BOOKTEST_H
