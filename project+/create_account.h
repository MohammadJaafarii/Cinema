#ifndef CREATE_ACCOUNT_H
#define CREATE_ACCOUNT_H

#include <QDialog>
namespace Ui {
class create_account;
}

class create_account : public QDialog
{
    Q_OBJECT

public:
    explicit create_account(QWidget *parent = nullptr);
    ~create_account();

private slots:
    void on_pushButton_clicked();



    void on_pushButton_5_clicked();

private:
    Ui::create_account *ui;
};

#endif // CREATE_ACCOUNT_H
