#ifndef CUSTOMER_PAGE_H
#define CUSTOMER_PAGE_H

#include <QDialog>

namespace Ui {
class customer_page;
}

class customer_page : public QDialog
{
    Q_OBJECT

public:
    explicit customer_page(QWidget *parent = nullptr);
    ~customer_page();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::customer_page *ui;
};

#endif // CUSTOMER_PAGE_H
