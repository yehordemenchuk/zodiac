#include <string>
#include <QMessageBox>
#include "dialog.h"
#include "ui_dialog.h"
#include "horoscop.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_prediction_button_clicked()
{
    string birth_date { ui->user_birth_date->text().toStdString() };
    string prediction_date { ui->current_date->text().toStdString() };

    if (is_date_valid(birth_date) && is_date_valid(prediction_date)) {
        ui->error_label->clear();

        QMessageBox::about(this, "Horoscop", "Your horoscop here");
    }

    else
        ui->error_label->setText("Enter valid date.");
}


void Dialog::on_exit_button_clicked()
{
    close();
}

