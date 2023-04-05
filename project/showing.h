 #ifndef SHOWING_H
#define SHOWING_H

#include <QDialog>

namespace Ui {
class showing;
}

class showing : public QDialog
{
    Q_OBJECT

public:
    explicit showing(QWidget *parent = nullptr);
    ~showing();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::showing *ui;
};

#endif // SHOWING_H
