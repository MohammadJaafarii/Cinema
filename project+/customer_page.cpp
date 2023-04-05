#include "customer_page.h"
#include "ui_customer_page.h"
#include <iostream>
#include <fstream>
#include <QString>
#include <QMessageBox>
#include <customer_page.h>
#include <second_page.h>
#include <book_ticket.h>
#include <show_history.h>
#include <searching_page.h>
using namespace std;
class user_pass{
public:
    string username;
    string password;
 };
customer_page::customer_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customer_page)
{
    ui->setupUi(this);
    user_pass customer;
    fstream file("Temp_username.txt" , ios ::in | ios :: app ) ;
    if ( file.is_open())
    {   string name;
        while (getline(file,name))
        {
           customer.username = name;
        }
    }
    file.close();
    QString m = QString ::fromStdString(customer.username);
   ui->label->setText(m + "'s Page");



}

customer_page::~customer_page()
{
    delete ui;
}

void customer_page::on_pushButton_clicked()
{
    Book_ticket * book = new Book_ticket();
    this->hide();
    book->show();
}

void customer_page::on_pushButton_5_clicked()
{
    second_page * second = new second_page();
    hide();
    second->show();
}

void customer_page::on_pushButton_3_clicked()
{
    Show_history *history = new Show_history();
    hide();
    history->show();
}

void customer_page::on_pushButton_2_clicked()
{
    searching_page *search = new searching_page();
    hide();
    search->show();

}
