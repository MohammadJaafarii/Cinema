#ifndef BOOK_PROGRESS_C_H
#define BOOK_PROGRESS_C_H

#include <QDialog>

namespace Ui {
class book_progress_c;
}

class book_progress_c : public QDialog
{
    Q_OBJECT

public:
    explicit book_progress_c(QWidget *parent = nullptr);
    ~book_progress_c();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::book_progress_c *ui;
};

#endif // BOOK_PROGRESS_C_H
