#include "userlist.h"
#include "ui_userlist.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>

UserList::UserList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserList)
{
    ui->setupUi(this);

    QFile userFile("user.txt");
    userFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&userFile);

    while (!in.atEnd()) {

        QString line = in.readLine();
        QStringList data= line.split(",");
        ui->comboBox->addItem(data.at(0));
    }

    userFile.close();
}

UserList::~UserList()
{
    delete ui;
}

void UserList::on_pushButton_clicked()
{

    QFile userFile("user.txt");
    userFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&userFile);

    QString username = ui->comboBox->itemText(ui->comboBox->currentIndex());

    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList data= line.split(",");

        if(data.at(0) == username)
        {
            QFile currentUserFile("current_user.txt");
            currentUserFile.open(QIODevice::WriteOnly | QIODevice::Text);
            QTextStream out(&currentUserFile);

            out<<data.at(0)<<","<<data.at(1)<<","<<data.at(2)<<","<<data.at(3)<<","<<data.at(4)<<","<<data.at(5)<<","<<data.at(6)<<","<<data.at(7)<<Qt::endl;

            break;
        }
    }


    this->hide();
    amp = new Adminmainpage(this);
    amp->show();
}

