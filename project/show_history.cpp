#include "show_history.h"
#include "ui_show_history.h"
#include <customer_page.h>
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
using namespace std;
class user_pass{
public:
    string username;
    string password;
};

Show_history::Show_history(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Show_history)
{
    ui->setupUi(this);
}

Show_history::~Show_history()
{
    delete ui;
}

void Show_history::on_pushButton_clicked()
{
    user_pass userpass;
    fstream file111("Temp_username.txt" , ios ::in | ios :: app ) ;
    if ( file111.is_open())
    {   string name;
        while (getline(file111,name))
        {
           userpass.username = name;
        }
    }
    file111.close();
    fstream file222("Temp_password.txt" , ios ::in | ios :: app ) ;
    if ( file222.is_open())
    {   string name;
        while (getline(file222,name))
        {
           userpass.password = name;
        }
    }
    file222.close();
    string abc = userpass.username+"_"+userpass.password+".txt" ;
    QString m3 = QString :: fromStdString(abc);




    QFile file6 (m3);

    if (!file6.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return ;
    }
    QTextStream in (&file6);

    ui->textBrowser->setText(in.readAll());
    file6.close();
}

void Show_history::on_pushButton_4_clicked()
{
    customer_page * customer = new customer_page();
    hide();
    customer->show();

}
