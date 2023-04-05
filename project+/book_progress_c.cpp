 #include "book_progress_c.h"
#include "ui_book_progress_c.h"
#include <book_ticket.h>
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
using namespace std;
FILE * shomaresh_show_booking_;
class user_pass{
public:
    string username;
    string password;
};

class information_movie{
public:
    string name_m;
    string director;
    string salon;
    string zarfiat;
    string price;

};
book_progress_c::book_progress_c(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::book_progress_c)
{
    ui->setupUi(this);
}

book_progress_c::~book_progress_c()
{
    delete ui;
}

void book_progress_c::on_pushButton_clicked()
{
    int number_of_movies = 0;
       fopen_s(&shomaresh_show_booking_, "shomaresh.txt", "ab");
       fclose(shomaresh_show_booking_);
       fopen_s(&shomaresh_show_booking_, "shomaresh.txt", "rb");
       if (!shomaresh_show_booking_)exit(0);
       fread(&number_of_movies,sizeof(int),1,shomaresh_show_booking_);
       fclose(shomaresh_show_booking_);
       information_movie * information = new information_movie[number_of_movies];
       int chosen_movie , number_of_ticket;
       int i = 0;
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

       chosen_movie = ui->lineEdit->text().toInt();
       chosen_movie = chosen_movie - 1;
       number_of_ticket = ui->lineEdit_2->text().toInt();
       int show_price = 0;
       QString m3 = QString :: fromStdString(information[chosen_movie].zarfiat);
       int a = m3.toInt();
       if (a == 0){
           ui->lineEdit_3->setText("---");

           QMessageBox::warning(this,"SIGN UP STATUS","<FONT COLOR='#00da69'> There Isn't Any Capacity For This Movie :( </FONT>");


       }
       else if (  a - number_of_ticket < 0){

           ui->lineEdit_3->setText("---");

           QMessageBox::warning(this,"SIGN UP STATUS","<FONT COLOR='#00da69'> There Isn't Enough Capacity For This Movie :( </FONT>");



       }
       else{
           int i = 0;
           fstream file1111("movie_name.txt" , ios ::in | ios :: app ) ;
           if ( file1111.is_open())
           {   string name;
               while (getline(file1111,name))
               {
                  information[i].name_m = name;
                  i++;
               }
           }
           file1111.close();
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
       fstream file9("price_movie.txt" , ios ::in | ios :: app ) ;
       if ( file9.is_open())
       {   string name;
           while (getline(file9,name))
           {
              if ( i == chosen_movie)
              {
                  QString m = QString :: fromStdString(name);
                  show_price = (m.toInt()) * number_of_ticket;
              }
              i++;

              }
           }

       file9.close();
       user_pass userpass;
       fstream file111("Temp_username.txt" , ios ::in | ios :: app ) ;
       if ( file111.is_open())
       {   string name;
           while (getline(file111,name))
           {
              userpass.username = name;
           }
       }
       file111.close();
       fstream file222("Temp_password.txt" , ios ::in | ios :: app ) ;
       if ( file222.is_open())
       {   string name;
           while (getline(file222,name))
           {
              userpass.password = name;
           }
       }
       file222.close();
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
       string m1 = to_string(show_price);

       ofstream file(userpass.username+"_"+userpass.password+".txt" , ios :: out | ios::app  ) ;
       if ( file.is_open())
       {
                   file << "Movie's Name : "<<information[chosen_movie].name_m <<endl;
                   file << "Movie's Director : "<<information[chosen_movie].director <<endl;
                   file << "Place : "<<information[chosen_movie].salon <<endl;
                   file << "Number Of Tickets : " << ui->lineEdit_2->text().toStdString()<<endl;
                   file << "Price : "<<m1 <<endl;
                   file << "------------------------------------------------"<<endl;

       }
       file.close();

       QString m2 = QString :: fromStdString(m1);
       ui->lineEdit_3->setText(m2);
       i = 0;
       a = a-number_of_ticket;
       information[chosen_movie].zarfiat =to_string(a);
       ofstream file13("zarfiat_salon.txt" , ios :: out   ) ;
       if ( file13.is_open())
       {
           for (int i = 0 ;i<number_of_movies;i++){
                   file13 <<information[i].zarfiat<<endl;

           }

       }
       file13.close();
       QMessageBox::information(this,"SIGN UP STATUS","<FONT COLOR='#00da69'> Tickets Were Successfully Booked :)</FONT>");

       }

       delete []  information;
}

void book_progress_c::on_pushButton_2_clicked()
{
    Book_ticket *book_s = new Book_ticket();
    hide();
    book_s->show();
}
