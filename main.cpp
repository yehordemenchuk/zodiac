#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication horoscop_application(argc, argv);
    MainWindow main_window;

    main_window.show();

    return horoscop_application.exec();
}
