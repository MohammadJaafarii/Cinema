#include "editing_progress.h"
#include "ui_editing_progress.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <boss_page.h>
#include <editing_progress.h>
#include <QMessageBox>
using namespace std;
FILE * shomaresh_re_p;
FILE * shomaresh_re_pp;
int chosen_m_editing;
class information_movie{
public:
    string name_m;
    string director;
    string genre;
    string actor[3];
    string salon;
    string zarfiat;
    string price;

};
Editing_progress::Editing_progress(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editing_progress)
{
    ui->setupUi(this);
    int number_of_movies = 0;
    fopen_s(&shomaresh_re_pp, "shomaresh.txt", "ab");
    fclose(shomaresh_re_pp);
    fopen_s(&shomaresh_re_pp, "shomaresh.txt", "rb");
    if (!shomaresh_re_pp)exit(0);
    fread(&number_of_movies,sizeof(int),1,shomaresh_re_pp);
    fclose(shomaresh_re_pp);
    information_movie * information = new information_movie[number_of_movies];
    int i = 0;
    fstream file("movie_name.txt" , ios ::in | ios :: app ) ;
    if ( file.is_open())
    {   string name;
        while (getline(file,name))
        {
           information[i].name_m = name;
           i++;
        }
    }
    file.close();
    i = 0;
    fstream file2("movie_director.txt" , ios ::in | ios :: app ) ;
    if ( file2.is_open())
    {   string name;
        while (getline(file2,name))
        {
           information[i].director = name;
           i++;
        }
    }
    file2.close();
    i = 0;
    fstream file3("genre_movie.txt" , ios ::in | ios :: app ) ;
    if ( file3.is_open())
    {   string name;
        while (getline(file3,name))
        {
           information[i].genre = name;
           i++;
        }
    }
    file3.close();
    i = 0;
    int b = 0;
    fstream file4("actor_actress_movie.txt" , ios ::in | ios :: app ) ;
    if ( file4.is_open())
    {   string name;
        while (getline(file4,name))
        {
            if (i == 3){
                i =0;
                b ++;
            }

           information[b].actor[i] = name;
           i++;

        }
    }
    file4.close();
    i = 0;
    fstream file7("salon_movie.txt" , ios ::in | ios :: app ) ;
    if ( file7.is_open())
    {   string name;
        while (getline(file7,name))
        {
           information[i].salon = name;
           i++;
        }
    }
    file7.close();
    i = 0;
    fstream file8("zarfiat_salon.txt" , ios ::in | ios :: app ) ;
    if ( file8.is_open())
    {   string name;
        while (getline(file8,name))
        {
           information[i].zarfiat = name;
           i++;
        }
    }
    file8.close();
    i = 0;
    fstream file9("price_movie.txt" , ios ::in | ios :: app ) ;
    if ( file9.is_open())
    {   string name;
        while (getline(file9,name))
        {
           information[i].price = name;
           i++;
        }
    }
    file9.close();
    fstream file11("Chosen_Number_editing.txt" , ios ::in | ios :: app ) ;
    if ( file11.is_open())
    {   string name;
        while (getline(file11,name))
        {
            QString change_to_int = QString::fromStdString(name);
            chosen_m_editing = change_to_int.toInt();
            chosen_m_editing = chosen_m_editing - 1;

        }
    }
    file11.close();
    QString m = QString::fromStdString(information[chosen_m_editing].name_m);
    ui->lineEdit->setText(m);
    QString m1 = QString::fromStdString(information[chosen_m_editing].director);
    ui->lineEdit_2->setText(m1);
    QString m2 = QString::fromStdString(information[chosen_m_editing].genre);
    ui->lineEdit_3->setText(m2);
    QString m3 = QString::fromStdString(information[chosen_m_editing].actor[0]);
    ui->lineEdit_4->setText(m3);
    QString m4 = QString::fromStdString(information[chosen_m_editing].actor[1]);
    ui->lineEdit_5->setText(m4);
    QString m5 = QString::fromStdString(information[chosen_m_editing].actor[2]);
    ui->lineEdit_6->setText(m5);
    QString m6 = QString::fromStdString(information[chosen_m_editing].salon);
    ui->lineEdit_7->setText(m6);
    QString m7 = QString::fromStdString(information[chosen_m_editing].zarfiat);
    ui->lineEdit_8->setText(m7);
    QString m8 = QString::fromStdString(information[chosen_m_editing].price);
    ui->lineEdit_9->setText(m8);
}

Editing_progress::~Editing_progress()
{
    delete ui;
}

void Editing_progress::on_pushButton_clicked()
{
    int number_of_movies = 0;
    fopen_s(&shomaresh_re_p, "shomaresh.txt", "ab");
    fclose(shomaresh_re_p);
    fopen_s(&shomaresh_re_p, "shomaresh.txt", "rb");
    if (!shomaresh_re_p)exit(0);
    fread(&number_of_movies,sizeof(int),1,shomaresh_re_p);
    fclose(shomaresh_re_p);
    information_movie * information = new information_movie[number_of_movies];
    int i = 0;
    fstream file("movie_name.txt" , ios ::in | ios :: app ) ;
    if ( file.is_open())
    {   string name;
        while (getline(file,name))
        {
           information[i].name_m = name;
           i++;
        }
    }
    file.close();
    i = 0;
    fstream file2("movie_director.txt" , ios ::in | ios :: app ) ;
    if ( file2.is_open())
    {   string name;
        while (getline(file2,name))
        {
           information[i].director = name;
           i++;
        }
    }
    file2.close();
    i = 0;
    fstream file3("genre_movie.txt" , ios ::in | ios :: app ) ;
    if ( file3.is_open())
    {   string name;
        while (getline(file3,name))
        {
           information[i].genre = name;
           i++;
        }
    }
    file3.close();
    i = 0;
    int b = 0;
    fstream file4("actor_actress_movie.txt" , ios ::in | ios :: app ) ;
    if ( file4.is_open())
    {   string name;
        while (getline(file4,name))
        {
            if (i == 3){
                i =0;
                b ++;
            }

           information[b].actor[i] = name;
           i++;

        }
    }
    file4.close();
    i = 0;
    fstream file7("salon_movie.txt" , ios ::in | ios :: app ) ;
    if ( file7.is_open())
    {   string name;
        while (getline(file7,name))
        {
           information[i].salon = name;
           i++;
        }
    }
    file7.close();
    i = 0;
    fstream file8("zarfiat_salon.txt" , ios ::in | ios :: app ) ;
    if ( file8.is_open())
    {   string name;
        while (getline(file8,name))
        {
           information[i].zarfiat = name;
           i++;
        }
    }
    file8.close();
    i = 0;
    fstream file9("price_movie.txt" , ios ::in | ios :: app ) ;
    if ( file9.is_open())
    {   string name;
        while (getline(file9,name))
        {
           information[i].price = name;
           i++;
        }
    }
    file9.close();


    information[chosen_m_editing].name_m = ui->lineEdit->text().toStdString();
    information[chosen_m_editing].director = ui->lineEdit_2->text().toStdString();
    information[chosen_m_editing].genre = ui->lineEdit_3->text().toStdString();
    information[chosen_m_editing].actor[0] = ui->lineEdit_4->text().toStdString();
    information[chosen_m_editing].actor[1] = ui->lineEdit_5->text().toStdString();
    information[chosen_m_editing].actor[2] = ui->lineEdit_6->text().toStdString();
    information[chosen_m_editing].salon = ui->lineEdit_7->text().toStdString();
    information[chosen_m_editing].zarfiat = ui->lineEdit_8->text().toStdString();
    information[chosen_m_editing].price = ui->lineEdit_9->text().toStdString();

    int chosen_movie = ui->lineEdit->text().toInt();
    ofstream file5("movie_name.txt" , ios :: out   ) ;
    if ( file5.is_open())
    {
        for (int i = 0 ;i<number_of_movies;i++){
            if (i != chosen_movie -1 ){
                file5 <<information[i].name_m<<endl;
            }
        }

    }
    file5.close();
    ofstream file6("movie_director.txt" , ios :: out   ) ;
    if ( file6.is_open())
    {
        for (int i = 0 ;i<number_of_movies;i++){
                file6 <<information[i].director<<endl;

        }

    }
    file6.close();
    ofstream file33("genre_movie.txt" , ios :: out   ) ;
    if ( file33.is_open())
    {
        for (int i = 0 ;i<number_of_movies;i++){
                file33 <<information[i].genre<<endl;

        }

    }
    file33.close();
    ofstream file22("actor_actress_movie.txt" , ios :: out   ) ;
    if ( file22.is_open())
    {
        for (int i = 0 ;i<number_of_movies;i++){
                for (int j = 0 ; j<3;j++){
                file22 <<information[i].actor[j]<<endl;

            }


    }
    }
    file22.close();
    ofstream file12("salon_movie.txt" , ios :: out   ) ;
    if ( file12.is_open())
    {
        for (int i = 0 ;i<number_of_movies;i++){
                file12 <<information[i].salon<<endl;

        }

    }
    file12.close();
    ofstream file13("zarfiat_salon.txt" , ios :: out   ) ;
    if ( file13.is_open())
    {
        for (int i = 0 ;i<number_of_movies;i++){
                file13 <<information[i].zarfiat<<endl;

        }

    }
    file13.close();
    ofstream file14("price_movie.txt" , ios :: out   ) ;
    if ( file14.is_open())
    {
        for (int i = 0 ;i<number_of_movies;i++){
                file14 <<information[i].price<<endl;

        }

    }
    file14.close();
    QMessageBox::information(this,"SIGN UP STATUS","<FONT COLOR='#00da69'> Changes saved successfully :)</FONT>");



}

void Editing_progress::on_pushButton_2_clicked()
{
    Boss_page * boss = new Boss_page();
    hide();
    boss->show();
}
