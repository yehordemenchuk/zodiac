#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include "horoscop.h"

namespace Ui {
class Dialog;
}

namespace dialog {
    const QString capricorn_image_name = "capricorn.gif";
    const QString aquarius_image_name = "aquarius.gif";
    const QString pisces_image_name = "pisces.gif";
    const QString aries_image_name = "aries.gif";
    const QString taurus_image_name = "taurus.gif";
    const QString gemini_image_name = "gemini.gif";
    const QString cancer_image_name = "cancer.gif";
    const QString leo_image_name = "leo.gif";
    const QString virgo_image_name = "virgo.gif";
    const QString libra_image_name = "libra.gif";
    const QString scorpio_image_name = "scorpio.gif";
    const QString sagitarius_image_name = "sagitarius.gif";

    const QString capricorn_message_title = "Capricorn";
    const QString aquaris_message_title = "Aquaris";
    const QString pisces_message_title = "Pisces";
    const QString aries_message_title = "Aries";
    const QString taurus_message_title = "Taurus";
    const QString gemini_message_title = "Gemini";
    const QString cancer_message_title = "Cancer";
    const QString leo_message_title = "Leo";
    const QString virgo_message_title = "Virgo";
    const QString libra_message_title = "Libra";
    const QString scorpio_message_title = "Scorpio";
    const QString sagitarius_message_title = "Sagitarius";

    const QString path_to_zodiac_icon = ":/img/zodiac_icon.png";
};

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void show_horoscop(string birth_date, string prediction_date);

    void on_prediction_button_clicked();

    void on_exit_button_clicked();

private:
    Ui::Dialog *ui;
};

void set_message(QMessageBox &message_box_ref, QString title, QString text, QString path_to_image);
void set_horoscop_message(QMessageBox &horoscop_message_ref, Horoscop_info user_horoscop);

#endif // DIALOG_H
