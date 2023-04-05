#ifndef EDITING_H
#define EDITING_H

#include <QDialog>

namespace Ui {
class Editing;
}

class Editing : public QDialog
{
    Q_OBJECT

public:
    explicit Editing(QWidget *parent = nullptr);
    ~Editing();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Editing *ui;
};

#endif // EDITING_H
