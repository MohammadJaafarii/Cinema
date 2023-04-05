#ifndef BOSS_PAGE_H
#define BOSS_PAGE_H

#include <QDialog>

namespace Ui {
class Boss_page;
}

class Boss_page : public QDialog
{
    Q_OBJECT

public:
    explicit Boss_page(QWidget *parent = nullptr);
    ~Boss_page();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Boss_page *ui;
};

#endif // BOSS_PAGE_H
