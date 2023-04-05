#include "boss_entrance.h"
#include "ui_boss_entrance.h"
#include <string>
#include <iostream>
#include <qstring.h>
#include <boss_page.h>
#include <QMessageBox>
#include <second_page.h>
Boss_entrance::Boss_entrance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Boss_entrance)
{
    ui->setupUi(this);
}

Boss_entrance::~Boss_entrance()
{
    delete ui;
}

void Boss_entrance::on_pushButton_clicked()
{

    bool check_boss = false;
    if (ui->lineEdit->text() == "Isfahan movie" && ui->lineEdit_2->text() == "1234")
    {
          QMessageBox::information(this,"SIGN UP STATUS","<FONT COLOR='#00da69'> You Signed in Successfully :)</FONT>");

        check_boss = true;
    }
    if (check_boss){
        Boss_page *boss = new Boss_page();
        hide();
        boss->show();
    }
    else      QMessageBox::warning(this,"SIGN UP STATUS","<FONT COLOR='#00da69'> USername Or Password isn't correct :(</FONT>");

}

void Boss_entrance::on_pushButton_5_clicked()
{
    second_page * second = new second_page();
    hide();
    second->show();
}
