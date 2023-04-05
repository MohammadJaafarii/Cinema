#include "create_account.h"
#include "ui_create_account.h"
#include <iostream>
#include <fstream>
#include <QString>
#include <QMessageBox>
#include <second_page.h>
#include <customer_page.h>
using namespace std;
FILE * shomaresh_d;
class user_pass{
public:
    string username;
    string password;
 };

create_account::create_account(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::create_account)
{
    ui->setupUi(this);
}

create_account::~create_account()
{
    delete ui;
}

void create_account::on_pushButton_clicked()
{
    int number_of_players = 0;
    fopen_s(&shomaresh_d, "shomaresh_customer.txt", "ab");
    fclose(shomaresh_d);
    fopen_s(&shomaresh_d, "shomaresh_customer.txt", "rb");
    if (!shomaresh_d)exit(0);
    fread(&number_of_players,sizeof(int),1,shomaresh_d);
    fclose(shomaresh_d);
    user_pass *usernamepass = new user_pass[number_of_players];
    fstream file("username.txt" , ios ::in | ios :: app ) ;
    if ( file.is_open())
    {   string name;
        int i = 0;
        while (getline(file,name))
        {
           usernamepass[i].username = name;
           i++;
        }
    }
    file.close();
    fstream file1("password.txt" , ios ::in | ios :: app ) ;
    if ( file1.is_open())
    {   string name;
        int i = 0;
        while (getline(file1,name))
        {
           usernamepass[i].password = name;
           i++;
        }
    }
    file1.close();
    string username_l , password_l;
    username_l = ui->lineEdit->text().toStdString();
    password_l = ui->lineEdit_2->text().toStdString();
    bool check_user_pass = true;
    int i= 0;
    for ( i = 0 ; i <number_of_players;i++){
    if (username_l == usernamepass[i].username && password_l == usernamepass[i].password)
    {   QMessageBox::warning(this,"SIGN UP STATUS","<FONT COLOR='#00da69'> Please Choose Other Username And Password :(</FONT>");
        check_user_pass = true;
        break;
    }
    }
    if ( i == number_of_players)check_user_pass = false;
    if (check_user_pass == false)  QMessageBox::information(this,"SIGN UP STATUS","<FONT COLOR='#00da69'> You Logged in Successfully :)</FONT>");
    delete [] usernamepass;
    if (check_user_pass == false){

    ofstream file3("username.txt" , ios :: out | ios::app  ) ;
    if ( file3.is_open())
    {

            file3 <<username_l<<endl;


    }
    file3.close();
    ofstream file4("password.txt" , ios :: out | ios::app  ) ;
    if ( file4.is_open())
    {

            file4 <<password_l<<endl;


    }
    file4.close();
    number_of_players++;
    fopen_s(&shomaresh_d, "shomaresh_customer.txt", "r+b");

        if (!shomaresh_d) {

            exit(0);
        }

        fwrite(&number_of_players, sizeof(int), 1, shomaresh_d);

        fclose(shomaresh_d);


    ofstream file6("Temp_username.txt" , ios :: out  ) ;
    if ( file6.is_open())
    {
        file6 << username_l <<endl;
    }
    file6.close();

    ofstream file7("Temp_password.txt" , ios :: out  ) ;
    if ( file7.is_open())
    {
        file7 << password_l <<endl;
    }
    file7.close();
    customer_page * customer= new customer_page();
    hide();
    customer->show();

    }
}





void create_account::on_pushButton_5_clicked()
{
    second_page * second = new second_page ();
    hide();
    second->show();
}
