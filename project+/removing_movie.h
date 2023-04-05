#ifndef REMOVING_MOVIE_H
#define REMOVING_MOVIE_H

#include <QDialog>

namespace Ui {
class Removing_movie;
}

class Removing_movie : public QDialog
{
    Q_OBJECT

public:
    explicit Removing_movie(QWidget *parent = nullptr);
    ~Removing_movie();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Removing_movie *ui;
};

#endif // REMOVING_MOVIE_H
