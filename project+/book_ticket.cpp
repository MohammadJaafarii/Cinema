#include "book_ticket.h"
#include "ui_book_ticket.h"
#include <customer_page.h>
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <book_progress_c.h>
using namespace std;
FILE *shomaresh_show_customer;
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
Book_ticket::Book_ticket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Book_ticket)
{
    ui->setupUi(this);
}

Book_ticket::~Book_ticket()
{
    delete ui;
}

void Book_ticket::on_pushButton_4_clicked()
{
    customer_page *customer = new customer_page();
    hide();
    customer->show();
}

void Book_ticket::on_pushButton_clicked()
{
    int number_of_movies = 0;
    fopen_s(&shomaresh_show_customer, "shomaresh.txt", "ab");
    fclose(shomaresh_show_customer);
    fopen_s(&shomaresh_show_customer, "shomaresh.txt", "rb");
    if (!shomaresh_show_customer)exit(0);
    fread(&number_of_movies,sizeof(int),1,shomaresh_show_customer);
    fclose(shomaresh_show_customer);
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

    ofstream file5("showing_movie_in_book_ticket.txt" , ios :: out  ) ;
    if ( file5.is_open())
    {
        if (number_of_movies == 0)file5 << "There isn't Any Information For Showing"<<endl;
        for (i = 0 ; i < number_of_movies;i++){
            file5<<i+1<<" : "<<endl;
            file5 <<"Movie's Name : "<< information[i].name_m <<endl;
            file5 <<"Movie's Director : "<<information[i].director<<endl;
            file5 << "Movie's Genre : "<<information[i].genre<<endl;
            file5 <<"Movie's Acter/Actress : "<<endl;
            file5 <<"1. "<<information[i].actor[0]<<endl;
            file5 <<"2. "<<information[i].actor[1]<<endl;
            file5 <<"3. "<<information[i].actor[2]<<endl;
            file5 << "Salon : "<<information[i].salon<<endl;
            file5 << "Zarfiate Baghimande : "<<information[i].zarfiat<<endl;
            file5 << "Price : "<<information[i].price<<endl;
            file5 << "------------------------------------------------"<<endl;

        }


    }
    file5.close();

    QFile file6 ("showing_movie_in_book_ticket.txt");

    if (!file6.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return ;
    }
    QTextStream in (&file6);
    if (number_of_movies != 0 ){
    ui->textBrowser->setText(in.readAll());
    file6.close();
    }
    else ui->textBrowser->setText("There isn't Any Information For Showing");
    delete [] information;
}

void Book_ticket::on_pushButton_5_clicked()
{
    book_progress_c * bookticket = new book_progress_c();
    this->hide();
    bookticket->show();
}
