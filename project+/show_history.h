#ifndef SHOW_HISTORY_H
#define SHOW_HISTORY_H

#include <QDialog>

namespace Ui {
class Show_history;
}

class Show_history : public QDialog
{
    Q_OBJECT

public:
    explicit Show_history(QWidget *parent = nullptr);
    ~Show_history();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Show_history *ui;
};

#endif // SHOW_HISTORY_H
