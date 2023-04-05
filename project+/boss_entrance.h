#ifndef BOSS_ENTRANCE_H
#define BOSS_ENTRANCE_H

#include <QDialog>

namespace Ui {
class Boss_entrance;
}

class Boss_entrance : public QDialog
{
    Q_OBJECT

public:
    explicit Boss_entrance(QWidget *parent = nullptr);
    ~Boss_entrance();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Boss_entrance *ui;
};

#endif // BOSS_ENTRANCE_H
