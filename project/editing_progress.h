#ifndef EDITING_PROGRESS_H
#define EDITING_PROGRESS_H

#include <QDialog>

namespace Ui {
class Editing_progress;
}

class Editing_progress : public QDialog
{
    Q_OBJECT

public:
    explicit Editing_progress(QWidget *parent = nullptr);
    ~Editing_progress();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Editing_progress *ui;
};

#endif // EDITING_PROGRESS_H
