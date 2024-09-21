#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "horoscop.h"

namespace Ui 
{
    class Dialog;
}

namespace dialog 
{
    const char capricorn_image_path[] = ":\\img\\capricorn.gif";
    const char aquarius_image_path[] = ":\\img\\aquarius.gif";
    const char pisces_image_path[] = ":\\img\\pisces.gif";
    const char aries_image_path[] = ":\\img\\aries.gif";
    const char taurus_image_path[] = ":\\img\\taurus.gif";
    const char gemini_image_path[] = ":\\img\\gemini.gif";
    const char cancer_image_path[] = ":\\img\\cancer.gif";
    const char leo_image_path[] = ":\\img\\leo.gif";
    const char virgo_image_path[] = ":\\img\\virgo.gif";
    const char libra_image_path[] = ":\\img\\libra.gif";
    const char scorpio_image_path[] = ":\\img\\scorpio.gif";
    const char sagitarius_image_path[] = ":\\img\\sagitarius.gif";

    const char capricorn_message_title[] = "Capricorn";
    const char aquaris_message_title[] = "Aquaris";
    const char pisces_message_title[] = "Pisces";
    const char aries_message_title[] = "Aries";
    const char taurus_message_title[] = "Taurus";
    const char gemini_message_title[] = "Gemini";
    const char cancer_message_title[] = "Cancer";
    const char leo_message_title[] = "Leo";
    const char virgo_message_title[] = "Virgo";
    const char libra_message_title[] = "Libra";
    const char scorpio_message_title[] = "Scorpio";
    const char sagitarius_message_title[] = "Sagitarius";

    const char window_icon_path[] = ":\\img\\window_icon.png";
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
