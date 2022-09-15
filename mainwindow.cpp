#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "interface.h"

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


void MainWindow::on_entrer_clicked()
{
    interface in;
    QString id=ui->login->text();
    QString mp=ui->password->text();
    if(id=="mehdi" && mp=="0000")
    {

        in.setModal(true);
        in.exec();
    }
}

void MainWindow::on_pushButton_clicked()
{
    close();
}

