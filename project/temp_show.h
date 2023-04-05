#ifndef TEMP_SHOW_H
#define TEMP_SHOW_H

#include <QDialog>

namespace Ui {
class temp_show;
}

class temp_show : public QDialog
{
    Q_OBJECT

public:
    explicit temp_show(QWidget *parent = nullptr);
    ~temp_show();

private slots:
    void on_pushButton_clicked();

private:
    Ui::temp_show *ui;
};

#endif // TEMP_SHOW_H
