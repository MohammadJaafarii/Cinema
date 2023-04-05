#ifndef SECOND_PAGE_H
#define SECOND_PAGE_H

#include <QDialog>
#include "create_account.h"
#include <sign_in.h>
namespace Ui {
class second_page;
}

class second_page : public QDialog
{
    Q_OBJECT

public:
    explicit second_page(QWidget *parent = nullptr);
    ~second_page();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::second_page *ui;
    create_account *creat_an_acoount;
    SIGN_IN *SIGNIN;
};

#endif // SECOND_PAGE_H
