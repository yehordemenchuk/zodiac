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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *prediction_button;
    QPushButton *exit_button;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *user_birth_date;
    QLabel *label_2;
    QLineEdit *current_date;
    QLabel *error_label;
    QLabel *label_3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/zodiac_icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Dialog->setWindowIcon(icon);
        Dialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
"	background-color: rgb(59, 61, 91);\n"
"}"));
        prediction_button = new QPushButton(Dialog);
        prediction_button->setObjectName("prediction_button");
        prediction_button->setGeometry(QRect(40, 230, 141, 29));
        prediction_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(85, 0, 127);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: darkviolet;\n"
"} \n"
"\n"
"QPushButton:pressed {\n"
"	background-color: indigo;\n"
"}"));
        exit_button = new QPushButton(Dialog);
        exit_button->setObjectName("exit_button");
        exit_button->setGeometry(QRect(220, 230, 141, 29));
        exit_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(85, 0, 127);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: darkviolet;\n"
"} \n"
"\n"
"QPushButton:pressed {\n"
"	background-color: indigo;\n"
"}"));
        widget = new QWidget(Dialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(120, 30, 160, 173));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        user_birth_date = new QLineEdit(widget);
        user_birth_date->setObjectName("user_birth_date");

        verticalLayout->addWidget(user_birth_date);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        current_date = new QLineEdit(widget);
        current_date->setObjectName("current_date");

        verticalLayout->addWidget(current_date);

        error_label = new QLabel(widget);
        error_label->setObjectName("error_label");

        verticalLayout->addWidget(error_label);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Zodiac", nullptr));
        prediction_button->setText(QCoreApplication::translate("Dialog", "Get prediction", nullptr));
        exit_button->setText(QCoreApplication::translate("Dialog", "Exit", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Enter your birth date", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Enter date of prediction", nullptr));
        error_label->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
