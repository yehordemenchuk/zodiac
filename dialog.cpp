#include <string>
#include <QMessageBox>
#include <QString>
#include <QPixmap>
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

void set_message(QMessageBox &message_box_ref, QString title, QString text, QString path_to_image, QString path_to_icon) {
    message_box_ref.setWindowTitle(title);

    message_box_ref.setText(text);

    QPixmap icon_pix_map(path_to_image), window_icon(path_to_icon);

    message_box_ref.setIconPixmap(icon_pix_map);

    message_box_ref.setWindowIcon(window_icon);
}

void set_horoscop_message(QMessageBox &horoscop_message_ref, Horoscop_info user_horoscop) {
    horoscop::zodiac_sign user_sign = user_horoscop.get_user_zodiac_sign();
    string user_prediction = user_horoscop.get_prediction();

    switch(user_sign) {
        case horoscop::CAPRICORN:
            set_message(horoscop_message_ref, dialog::capricorn_message_title, user_prediction.c_str(), dialog::capricorn_image_name,
                        dialog::path_to_zodiac_icon);

            break;

        case horoscop::AQUARIUS:
            set_message(horoscop_message_ref, dialog::aquaris_message_title, user_prediction.c_str(), dialog::aquarius_image_name,
                        dialog::path_to_zodiac_icon);

            break;

        case horoscop::PISCES:
            set_message(horoscop_message_ref, dialog::pisces_message_title, user_prediction.c_str(), dialog::pisces_image_name,
                        dialog::path_to_zodiac_icon);

            break;

        case horoscop::ARIES:
            set_message(horoscop_message_ref, dialog::aries_message_title, user_prediction.c_str(), dialog::aries_image_name,
                        dialog::path_to_zodiac_icon);

            break;

        case horoscop::TAURUS:
            set_message(horoscop_message_ref, dialog::taurus_message_title, user_prediction.c_str(), dialog::taurus_image_name,
                        dialog::path_to_zodiac_icon);

            break;

        case horoscop::GEMINI:
            set_message(horoscop_message_ref, dialog::gemini_message_title, user_prediction.c_str(), dialog::gemini_image_name,
                        dialog::path_to_zodiac_icon);

            break;

        case horoscop::CANCER:
            set_message(horoscop_message_ref, dialog::cancer_message_title, user_prediction.c_str(), dialog::cancer_image_name,
                        dialog::path_to_zodiac_icon);

            break;

        case horoscop::LEO:
            set_message(horoscop_message_ref, dialog::leo_message_title, user_prediction.c_str(), dialog::leo_image_name,
                        dialog::path_to_zodiac_icon);

            break;

        case horoscop::VIRGO:
            set_message(horoscop_message_ref, dialog::virgo_message_title, user_prediction.c_str(), dialog::virgo_image_name,
                        dialog::path_to_zodiac_icon);

            break;

        case horoscop::LIBRA:
            set_message(horoscop_message_ref, dialog::libra_message_title, user_prediction.c_str(), dialog::libra_image_name,
                        dialog::path_to_zodiac_icon);

            break;

        case horoscop::SCORPIO:
            set_message(horoscop_message_ref, dialog::scorpio_message_title, user_prediction.c_str(), dialog::scorpio_image_name,
                        dialog::path_to_zodiac_icon);

            break;

        case horoscop::SAGGITARIUS:
            set_message(horoscop_message_ref, dialog::sagitarius_message_title, user_prediction.c_str(), dialog::sagitarius_image_name,
                        dialog::path_to_zodiac_icon);

            break;
    }
}

void Dialog::show_horoscop(string birth_date, string prediction_date) {
    ui->error_label->clear();

    Horoscop_info user_horoscop;

    user_horoscop.set_horoscop_data(birth_date, prediction_date);

    QMessageBox horoscop_message;

    set_horoscop_message(horoscop_message, user_horoscop);

    horoscop_message.exec();
}

void Dialog::on_prediction_button_clicked()
{
    string birth_date { ui->user_birth_date->text().toStdString() };
    string prediction_date { ui->current_date->text().toStdString() };

    if (is_date_valid(birth_date) && is_date_valid(prediction_date))
        show_horoscop(birth_date, prediction_date);

    else
        ui->error_label->setText("Enter valid date.");
}


void Dialog::on_exit_button_clicked()
{
    close();
}

