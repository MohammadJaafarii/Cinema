#ifndef SIGN_IN_H
#define SIGN_IN_H

#include <QDialog>

namespace Ui {
class SIGN_IN;
}

class SIGN_IN : public QDialog
{
    Q_OBJECT

public:
    explicit SIGN_IN(QWidget *parent = nullptr);
    ~SIGN_IN();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_5_clicked();

private:
    Ui::SIGN_IN *ui;
};

#endif // SIGN_IN_H
