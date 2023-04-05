#include "sign_in.h"
#include "ui_sign_in.h"
#include <iostream>
#include <fstream>
#include <QString>
#include <QMessageBox>
#include <customer_page.h>
#include <second_page.h>
using namespace std;
FILE *shomaresh;
class user_pass{
public:
    string username;
    string password;
 };
SIGN_IN::SIGN_IN(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SIGN_IN)
{
    ui->setupUi(this);
}

SIGN_IN::~SIGN_IN()
{
    delete ui;
}

void SIGN_IN::on_pushButton_clicked()
{
    int number_of_players = 0;
    fopen_s(&shomaresh, "shomaresh_customer.txt", "ab");
    fclose(shomaresh);
    fopen_s(&shomaresh, "shomaresh_customer.txt", "rb");
    if (!shomaresh)exit(0);
    fread(&number_of_players,sizeof(int),1,shomaresh);
    fclose(shomaresh);
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
    bool check_user_pass = false;
    int i= 0;
    for ( i = 0 ; i <number_of_players;i++){
    if (username_l == usernamepass[i].username && password_l == usernamepass[i].password)
    {   QMessageBox::information(this,"SIGN UP STATUS","<FONT COLOR='#00da69'> You Signed in Successfully :)</FONT>");
        ofstream file6("Temp_username.txt" , ios :: out  ) ;
        if ( file6.is_open())
        {
            file6 << usernamepass[i].username <<endl;
        }
        file6.close();

        ofstream file7("Temp_password.txt" , ios :: out  ) ;
        if ( file7.is_open())
        {
            file7 << usernamepass[i].password <<endl;
        }
        file7.close();
        customer_page * customer= new customer_page();
        hide();
        customer->show();
        break;
    }
    }
    if ( i == number_of_players)check_user_pass = true;
    if (check_user_pass)  QMessageBox::warning(this,"SIGN UP STATUS","<FONT COLOR='#00da69'> There Isn't Any Member With This Username And Password:(</FONT>");
}



void SIGN_IN::on_pushButton_5_clicked()
{
    second_page * second = new second_page();
    hide();
    second->show();
}
