#ifndef SAVING_MOVIE_H
#define SAVING_MOVIE_H

#include <QDialog>

namespace Ui {
class saving_movie;
}

class saving_movie : public QDialog
{
    Q_OBJECT

public:
    explicit saving_movie(QWidget *parent = nullptr);
    ~saving_movie();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::saving_movie *ui;
};

#endif // SAVING_MOVIE_H
