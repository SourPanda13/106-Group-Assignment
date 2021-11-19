//Library and Header Files
#include "testview.h"
#include "ui_testview.h"
#include <QFile>

//Window that displays a users test results

TestView::TestView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestView)
{
    ui->setupUi(this);

    //Displays all of the user's tests in the test file
    QFile CurrentUserFile("current_user.txt");
    CurrentUserFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&CurrentUserFile);

    QString line = in.readLine();
    QStringList data= line.split(",");

    QString email=data.at(0);

    QFile testFile("tests.txt");
    testFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream testIn(&testFile);

    while(!testIn.atEnd())
    {
        QString t_line = testIn.readLine();
        QStringList t_data= t_line.split(",");

        if(t_data.at(0) == email)
        {
            ui->textEdit->append(t_data.at(1) + " " + t_data.at(2) + "\n");
        }
    }

}

TestView::~TestView()
{
    delete ui;
}
