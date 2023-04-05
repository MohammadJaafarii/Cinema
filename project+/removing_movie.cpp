#include "removing_movie.h"
#include "ui_removing_movie.h"
#include <boss_page.h>
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>

using namespace std;
FILE * shomaresh_r;
FILE * shomaresh_r_m;
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

Removing_movie::Removing_movie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Removing_movie)
{
    ui->setupUi(this);
}

Removing_movie::~Removing_movie()
{
    delete ui;
}

void Removing_movie::on_pushButton_4_clicked()
{
    Boss_page *boss = new Boss_page();
    hide();
    boss->show();
}


void Removing_movie::on_pushButton_3_clicked()
{
    int number_of_movies = 0;
    fopen_s(&shomaresh_r, "shomaresh.txt", "ab");
    fclose(shomaresh_r);
    fopen_s(&shomaresh_r, "shomaresh.txt", "rb");
    if (!shomaresh_r)exit(0);
    fread(&number_of_movies,sizeof(int),1,shomaresh_r);
    fclose(shomaresh_r);
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

    ofstream file5("removing_name_movie.txt" , ios :: out  ) ;
    if ( file5.is_open())
    {
        if (number_of_movies == 0)file5 << "There isn't Any Information For Showing"<<endl;
        for (i = 0 ; i < number_of_movies;i++){
            file5 <<i + 1<<". "<< information[i].name_m <<endl;
            file5 << "------------------------------------------------"<<endl;

        }


    }
    file5.close();
    QFile file6 ("removing_name_movie.txt");

    if (!file6.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return ;
    }
    QTextStream in (&file6);

    ui->textBrowser->setText(in.readAll());
    file.close();

    delete [] information;


}

void Removing_movie::on_pushButton_2_clicked()
{
    int number_of_movies = 0;
    fopen_s(&shomaresh_r, "shomaresh.txt", "ab");
    fclose(shomaresh_r);
    fopen_s(&shomaresh_r, "shomaresh.txt", "rb");
    if (!shomaresh_r)exit(0);
    fread(&number_of_movies,sizeof(int),1,shomaresh_r);
    fclose(shomaresh_r);
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
    fstream file9("salon_movie.txt" , ios ::in | ios :: app ) ;
    if ( file9.is_open())
    {   string name;
        while (getline(file9,name))
        {
           information[i].salon = name;
           i++;
        }
    }
    file9.close();
    i = 0;
    fstream file10("zarfiat_salon.txt" , ios ::in | ios :: app ) ;
    if ( file10.is_open())
    {   string name;
        while (getline(file10,name))
        {
           information[i].zarfiat = name;
           i++;
        }
    }
    file10.close();
    i = 0;
    fstream file11("price_movie.txt" , ios ::in | ios :: app ) ;
    if ( file11.is_open())
    {   string name;
        while (getline(file11,name))
        {
           information[i].price = name;
           i++;
        }
    }
    file11.close();
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
            if (i != chosen_movie -1 ){
                file6 <<information[i].director<<endl;
            }
        }

    }
    file6.close();
    ofstream file7("genre_movie.txt" , ios :: out   ) ;
    if ( file7.is_open())
    {
        for (int i = 0 ;i<number_of_movies;i++){
            if (i != chosen_movie -1 ){
                file7 <<information[i].genre<<endl;
            }
        }

    }
    file7.close();
    ofstream file8("actor_actress_movie.txt" , ios :: out   ) ;
    if ( file8.is_open())
    {
        for (int i = 0 ;i<number_of_movies;i++){
            if (i != chosen_movie -1 ){
                for (int j = 0 ; j<3;j++){
                file8 <<information[i].actor[j]<<endl;
                }
            }
        }

    }
    file8.close();
    ofstream file12("salon_movie.txt" , ios :: out   ) ;
    if ( file12.is_open())
    {
        for (int i = 0 ;i<number_of_movies;i++){
            if (i != chosen_movie -1 ){
                file12 <<information[i].salon<<endl;
            }
        }

    }
    file12.close();
    ofstream file13("zarfiat_salon.txt" , ios :: out   ) ;
    if ( file13.is_open())
    {
        for (int i = 0 ;i<number_of_movies;i++){
            if (i != chosen_movie -1 ){
                file13 <<information[i].zarfiat<<endl;
            }
        }

    }
    file13.close();
    ofstream file14("price_movie.txt" , ios :: out   ) ;
    if ( file14.is_open())
    {
        for (int i = 0 ;i<number_of_movies;i++){
            if (i != chosen_movie -1 ){
                file14 <<information[i].price<<endl;
            }
        }

    }
    file14.close();
    if (number_of_movies !=0){

        ui->textBrowser->setText("The Movie Removed Successfully :)");


    number_of_movies--;
    fopen_s(&shomaresh_r_m, "shomaresh.txt", "r+b");

        if (!shomaresh_r_m) {

            exit(0);
        }

        fwrite(&number_of_movies, sizeof(int), 1, shomaresh_r_m);

        fclose(shomaresh_r_m);
    }


        delete [] information;


}
