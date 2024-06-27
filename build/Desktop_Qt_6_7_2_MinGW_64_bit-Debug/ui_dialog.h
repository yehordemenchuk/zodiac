/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLineEdit *user_birth_date;
    QLabel *label;
    QLineEdit *current_date;
    QLabel *label_2;
    QPushButton *prediction_button;
    QLabel *label_3;
    QPushButton *exit_button;
    QLabel *error_label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/zodiac_icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Dialog->setWindowIcon(icon);
        user_birth_date = new QLineEdit(Dialog);
        user_birth_date->setObjectName("user_birth_date");
        user_birth_date->setGeometry(QRect(100, 50, 161, 28));
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 20, 141, 20));
        current_date = new QLineEdit(Dialog);
        current_date->setObjectName("current_date");
        current_date->setGeometry(QRect(100, 120, 161, 28));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 90, 161, 20));
        prediction_button = new QPushButton(Dialog);
        prediction_button->setObjectName("prediction_button");
        prediction_button->setGeometry(QRect(40, 230, 141, 29));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(120, 170, 63, 20));
        exit_button = new QPushButton(Dialog);
        exit_button->setObjectName("exit_button");
        exit_button->setGeometry(QRect(220, 230, 141, 29));
        error_label = new QLabel(Dialog);
        error_label->setObjectName("error_label");
        error_label->setGeometry(QRect(130, 160, 101, 20));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Zodiac", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Enter your birth date", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Enter date of prediction", nullptr));
        prediction_button->setText(QCoreApplication::translate("Dialog", "Get prediction", nullptr));
        label_3->setText(QString());
        exit_button->setText(QCoreApplication::translate("Dialog", "Exit", nullptr));
        error_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
