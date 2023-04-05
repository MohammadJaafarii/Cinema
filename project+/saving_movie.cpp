#include "saving_movie.h"
#include "ui_saving_movie.h"
#include <iostream>
#include <fstream>
#include <QMessageBox>
#include <boss_page.h>
FILE * shomaresh_m;
using namespace std;
saving_movie::saving_movie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saving_movie)
{
    ui->setupUi(this);
}

saving_movie::~saving_movie()
{
    delete ui;
}

void saving_movie::on_pushButton_clicked()
{

    ofstream file1("movie_name.txt" , ios :: out | ios::app  ) ;
    if ( file1.is_open())
    {

            file1 <<ui->lineEdit->text().toStdString()<<endl;


    }
    file1.close();
    ofstream file2("movie_director.txt" , ios :: out | ios::app  ) ;
    if ( file2.is_open())
    {

            file2 <<ui->lineEdit_2->text().toStdString()<<endl;


    }
    file2.close();
    ofstream file3("genre_movie.txt" , ios :: out | ios::app  ) ;
    if ( file3.is_open())
    {

            file3 <<ui->lineEdit_3->text().toStdString()<<endl;


    }
    file3.close();
    ofstream file4("actor_actress_movie.txt" , ios :: out | ios::app  ) ;
    if ( file4.is_open())
    {

            file4 <<ui->lineEdit_4->text().toStdString()<<endl;
            file4 <<ui->lineEdit_5->text().toStdString()<<endl;
            file4 << ui->lineEdit_6->text().toStdString()<<endl;


    }
    file4.close();
    ofstream file5("salon_movie.txt" , ios :: out | ios::app  ) ;
    if ( file5.is_open())
    {

            file5 <<ui->lineEdit_7->text().toStdString()<<endl;



    }
    file5.close();
    ofstream file6("zarfiat_salon.txt" , ios :: out | ios::app  ) ;
    if ( file6.is_open())
    {

            file6 <<ui->lineEdit_8->text().toStdString()<<endl;



    }
    file6.close();
    ofstream file7("price_movie.txt" , ios :: out | ios::app  ) ;
    if ( file7.is_open())
    {

            file7 <<ui->lineEdit_9->text().toStdString()<<endl;



    }
    file7.close();

    QMessageBox::information(this,"SIGN UP STATUS","<FONT COLOR='#00da69'> Information saved successfully :)</FONT>");
    int number_of_movies = 0;
    fopen_s(&shomaresh_m, "shomaresh.txt", "ab");
    fclose(shomaresh_m);
    fopen_s(&shomaresh_m, "shomaresh.txt", "rb");
    if (!shomaresh_m)exit(0);
    fread(&number_of_movies,sizeof(int),1,shomaresh_m);
    fclose(shomaresh_m);
    number_of_movies++;
    fopen_s(&shomaresh_m, "shomaresh.txt", "r+b");

        if (!shomaresh_m) {

            exit(0);
        }

        fwrite(&number_of_movies, sizeof(int), 1, shomaresh_m);

        fclose(shomaresh_m);
}

void saving_movie::on_pushButton_2_clicked()
{
    Boss_page *boss = new Boss_page();
    hide();
    boss->show();
}
