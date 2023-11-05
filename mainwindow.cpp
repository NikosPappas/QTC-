#include "mainwindow.h"
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


void MainWindow::on_convert_clicked()
{
    QString input=ui->cels_input->text();
    if(input==""){
        QMessageBox::information(this,"Input Error","Failed to convert temperature.Please try again...");
    }
    else{
        double cel=input.toDouble();//converted celsius string from string to double
        double f=cel*(9/5)+32;
        ui->fahr_output->setText(QString::number(f));
    }
}


void MainWindow::on_clear_clicked()
{
    ui->cels_input->setText("");
    ui->fahr_output->setText("");
}

