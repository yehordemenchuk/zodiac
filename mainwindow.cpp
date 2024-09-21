#include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horoscop_button_clicked()
{
    close();

    Dialog dialog_window;

    dialog_window.setModal(true);

    dialog_window.exec();
}
