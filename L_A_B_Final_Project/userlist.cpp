#include "userlist.h"
#include "ui_userlist.h"
#include <QFile>
#include <QTextStream>
#include <QString>

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
}

UserList::~UserList()
{
    delete ui;
}
