#include "testinput.h"
#include "ui_testinput.h"

#include<QFile>
#include<QMessageBox>
#include<QString>

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

    //Would add a QMessageBox here but for some reason doing that causes the program to terminate

}

