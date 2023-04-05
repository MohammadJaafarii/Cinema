#include "searching_page.h"
#include "ui_searching_page.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <customer_page.h>
using namespace std;
FILE *shomaresh_show_search;

int number_of_movies = 0;
class information_movie{
public:
    string name_m;
    string director;
    string genre;
    string actor[3];


};
searching_page::searching_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searching_page)
{
    ui->setupUi(this);
    ui->lineEdit->setText("Search According To : ");
    fopen_s(&shomaresh_show_search, "shomaresh.txt", "ab");
    fclose(shomaresh_show_search);
    fopen_s(&shomaresh_show_search, "shomaresh.txt", "rb");
    if (!shomaresh_show_search)exit(0);
    fread(&number_of_movies,sizeof(int),1,shomaresh_show_search);
    fclose(shomaresh_show_search);

}

searching_page::~searching_page()
{
    delete ui;
}


void searching_page::on_pushButton_2_clicked()
{
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
    ofstream file5("searching_temp.txt" , ios :: out  ) ;

    string finding;
    finding = ui->lineEdit_2->text().toStdString();
    int count = 0;
    for (int i = 0 ;i <number_of_movies;i++){
        if (information[i].name_m == finding)
        { count++;
            file5 << count<<"." <<endl;
            file5<<"Movie's Name : " <<information[i].name_m<<endl;
            file5 << "Director : " <<information[i].director<<endl;
            file5 <<"Genre : "<<information[i].genre<<endl;
            file5 <<"First Actor/Actress : " << information[i].actor[0]<<endl;
            file5 << "Second Actor/Actress : "<<information[i].actor[1]<<endl;
            file5 <<"Third Actor/Actress : "<<information[i].actor[2]<<endl;
            file5 << "------------------------------------------------"<<endl;

        }
    }
    if (count ==0)file5 <<"Not Result"<<endl;
    QFile file6 ("searching_temp.txt");

    if (!file6.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return ;
    }
    QTextStream in (&file6);
    ui->lineEdit->setText("Result Of Searching According Movie's Name : ");
    ui->textBrowser->setText(in.readAll());

    file6.close();
    delete [] information;

}

void searching_page::on_pushButton_5_clicked()
{
    customer_page *customer = new customer_page();
    hide();
    customer->show();
}

void searching_page::on_pushButton_clicked()
{
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
    ofstream file5("searching_temp.txt" , ios :: out  ) ;

    string finding;
    finding = ui->lineEdit_2->text().toStdString();
    int count = 0;
    for (int i = 0 ;i <number_of_movies;i++){
        if (information[i].director == finding)
        { count++;
            file5 << count<<"." <<endl;
            file5<<"Movie's Name : " <<information[i].name_m<<endl;
            file5 << "Director : " <<information[i].director<<endl;
            file5 <<"Genre : "<<information[i].genre<<endl;
            file5 <<"First Actor/Actress : " << information[i].actor[0]<<endl;
            file5 << "Second Actor/Actress : "<<information[i].actor[1]<<endl;
            file5 <<"Third Actor/Actress : "<<information[i].actor[2]<<endl;
            file5 << "------------------------------------------------"<<endl;

        }
    }
    if (count ==0)file5 <<"Not Result"<<endl;
    QFile file6 ("searching_temp.txt");

    if (!file6.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return ;
    }
    QTextStream in (&file6);
    ui->lineEdit->setText("Result Of Searching According Director's Name : ");
    ui->textBrowser->setText(in.readAll());

    file6.close();
    delete [] information;
}

void searching_page::on_pushButton_3_clicked()
{
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
    ofstream file5("searching_temp.txt" , ios :: out  ) ;

    string finding;
    finding = ui->lineEdit_2->text().toStdString();
    int count = 0;
    for (int i = 0 ;i <number_of_movies;i++){
        if (information[i].genre == finding)
        { count++;
            file5 << count<<"." <<endl;
            file5<<"Movie's Name : " <<information[i].name_m<<endl;
            file5 << "Director : " <<information[i].director<<endl;
            file5 <<"Genre : "<<information[i].genre<<endl;
            file5 <<"First Actor/Actress : " << information[i].actor[0]<<endl;
            file5 << "Second Actor/Actress : "<<information[i].actor[1]<<endl;
            file5 <<"Third Actor/Actress : "<<information[i].actor[2]<<endl;
            file5 << "------------------------------------------------"<<endl;

        }
    }
    if (count ==0)file5 <<"Not Result"<<endl;
    QFile file6 ("searching_temp.txt");

    if (!file6.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return ;
    }
    QTextStream in (&file6);
    ui->lineEdit->setText("Result Of Searching According Genre : ");
    ui->textBrowser->setText(in.readAll());

    file6.close();
    delete [] information;
}



void searching_page::on_pushButton_4_clicked()
{
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
    ofstream file5("searching_temp.txt" , ios :: out  ) ;

    string finding;
    finding = ui->lineEdit_2->text().toStdString();
    int count = 0;
    for (int i = 0 ;i <number_of_movies;i++){
        for (int j = 0 ; j<3 ; j++){
        if (information[i].actor[j] == finding)
        { count++;
            file5 << count<<"." <<endl;
            file5<<"Movie's Name : " <<information[i].name_m<<endl;
            file5 << "Director : " <<information[i].director<<endl;
            file5 <<"Genre : "<<information[i].genre<<endl;
            file5 <<"First Actor/Actress : " << information[i].actor[0]<<endl;
            file5 << "Second Actor/Actress : "<<information[i].actor[1]<<endl;
            file5 <<"Third Actor/Actress : "<<information[i].actor[2]<<endl;
            file5 << "------------------------------------------------"<<endl;

        }
    }
    }
    if (count ==0)file5 <<"Not Result"<<endl;
    QFile file6 ("searching_temp.txt");

    if (!file6.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return ;
    }
    QTextStream in (&file6);
    ui->lineEdit->setText("Result Of Searching According Actor's/Actress's Name : ");
    ui->textBrowser->setText(in.readAll());

    file6.close();
    delete [] information;
}
