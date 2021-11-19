//Library and Header Files
#include "testinput.h"
#include "ui_testinput.h"

#include<QFile>
#include<QMessageBox>
#include<QString>
#include<QDateTime>

//Window that allows admin to enter the Covid test results of a user

TestInput::TestInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestInput)
{
    ui->setupUi(this);
}

TestInput::~TestInput()
{
    delete ui;
}

//Takes test result input from the admin and stores it in the test file
void TestInput::on_buttonBox_accepted()
{
    QFile currentUserFile("current_user.txt");
    currentUserFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&currentUserFile);

    QString line = in.readLine();
    QStringList data= line.split(",");

    QFile testFile("tests.txt");
    testFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    QTextStream out(&testFile);

    out<<data.at(0)<<","<<ui->dateEdit->date().toString()<<","<<ui->comboBox->currentText()<<Qt::endl;

    QFile log("testlog.txt");
    log.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    QTextStream l_out(&log);

    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();

    l_out << data.at(0) << "," << date.toString() << "," << time.toString() << Qt::endl;

    //Would add a QMessageBox here but for some reason doing that causes the program to terminate

}

