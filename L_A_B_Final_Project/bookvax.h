#ifndef BOOKVAX_H
#define BOOKVAX_H

#include <QDialog>

namespace Ui {
class BookVax;
}

class BookVax : public QDialog
{
    Q_OBJECT

public:
    explicit BookVax(QWidget *parent = nullptr);
    ~BookVax();

private:
    Ui::BookVax *ui;
};

#endif // BOOKVAX_H
