#include "editing.h"
#include "ui_editing.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <boss_page.h>
#include <editing_progress.h>
using namespace std;
FILE * shomaresh_re;
FILE * shomaresh_r_editing;

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
Editing::Editing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editing)
{
    ui->setupUi(this);
}

Editing::~Editing()
{
    delete ui;
}

void Editing::on_pushButton_2_clicked()
{
    int number_of_movies = 0;
    fopen_s(&shomaresh_re, "shomaresh.txt", "ab");
    fclose(shomaresh_re);
    fopen_s(&shomaresh_re, "shomaresh.txt", "rb");
    if (!shomaresh_re)exit(0);
    fread(&number_of_movies,sizeof(int),1,shomaresh_re);
    fclose(shomaresh_re);
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

void Editing::on_pushButton_clicked()
{
    int number_of_movies = 0;
    fopen_s(&shomaresh_r_editing, "shomaresh.txt", "ab");
    fclose(shomaresh_r_editing);
    fopen_s(&shomaresh_r_editing, "shomaresh.txt", "rb");
    if (!shomaresh_r_editing)exit(0);
    fread(&number_of_movies,sizeof(int),1,shomaresh_r_editing);
    fclose(shomaresh_r_editing);
    ofstream file10("Chosen_Number_editing.txt" , ios :: out  ) ;
    if ( file10.is_open())
    {

        file10 << ui->lineEdit->text().toStdString()<<endl;

    }
    file10.close();
    if (number_of_movies !=0){
    Editing_progress * progress = new Editing_progress();
    hide();
    progress->show();
    }
    else ui->textBrowser->setText("There isn't Any Information For Showing");

}

void Editing::on_pushButton_4_clicked()
{
    Boss_page * boss = new Boss_page();
    hide();
    boss->show();
}
