#include "second_page.h"
#include "ui_second_page.h"
#include <boss_entrance.h>
second_page::second_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::second_page)
{
    ui->setupUi(this);
}

second_page::~second_page()
{
    delete ui;
}

void second_page::on_pushButton_2_clicked()
{
    creat_an_acoount = new create_account();
    hide();
    creat_an_acoount->show();
}

void second_page::on_pushButton_4_clicked()
{
    exit(0);
}

void second_page::on_pushButton_clicked()
{

    Boss_entrance *boss = new Boss_entrance();
    hide();
    boss->show();
}

void second_page::on_pushButton_3_clicked()
{
    SIGNIN = new SIGN_IN();
    hide();
    SIGNIN->show();
}
