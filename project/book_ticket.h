#ifndef BOOK_TICKET_H
#define BOOK_TICKET_H

#include <QDialog>

namespace Ui {
class Book_ticket;
}

class Book_ticket : public QDialog
{
    Q_OBJECT

public:
    explicit Book_ticket(QWidget *parent = nullptr);
    ~Book_ticket();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Book_ticket *ui;
};

#endif // BOOK_TICKET_H
