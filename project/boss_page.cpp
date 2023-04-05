#include "boss_page.h"
#include "ui_boss_page.h"
#include <saving_movie.h>
#include <removing_movie.h>
#include <editing.h>
#include <showing.h>
#include <second_page.h>
Boss_page::Boss_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Boss_page)
{
    ui->setupUi(this);
}

Boss_page::~Boss_page()
{
    delete ui;
}

void Boss_page::on_pushButton_clicked()
{
    saving_movie * save = new saving_movie();
    hide();
    save->show();
}

void Boss_page::on_pushButton_2_clicked()
{
    Removing_movie *remove = new Removing_movie();
    hide();
    remove->show();
}

void Boss_page::on_pushButton_3_clicked()
{
    Editing * edit = new Editing();
    hide();
    edit->show();

}

void Boss_page::on_pushButton_4_clicked()
{
   showing *show = new showing();
    hide();
    show->show();
}

void Boss_page::on_pushButton_5_clicked()
{
    second_page *second = new second_page();
    hide();
    second->show();
}
