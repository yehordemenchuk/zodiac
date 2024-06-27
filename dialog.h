#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_prediction_button_clicked();

    void on_exit_button_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
