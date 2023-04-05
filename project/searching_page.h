#ifndef SEARCHING_PAGE_H
#define SEARCHING_PAGE_H

#include <QDialog>

namespace Ui {
class searching_page;
}

class searching_page : public QDialog
{
    Q_OBJECT

public:
    explicit searching_page(QWidget *parent = nullptr);
    ~searching_page();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::searching_page *ui;
};

#endif // SEARCHING_PAGE_H
