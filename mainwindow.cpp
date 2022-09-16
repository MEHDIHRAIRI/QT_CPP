#include <QtDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QPixmap>
#include <QtWidgets>


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString place ="C:/Users/mehdi/Documents/Projet_Mehdi/foundergif.gif";
    ui->label->setMask((new QPixmap(place))->mask());
    QMovie *movie=new QMovie(place);
    ui->label->setMovie(movie);
    movie->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_entrer_clicked()
{
    Dialog d;
    QString id=ui->login->text();
    QString mp=ui->password->text();
    if(id=="mehdi" && mp=="0000")
    {
        d.setModal(true);
        d.exec();
    }
}

void MainWindow::on_pushButton_clicked()
{
    close();
}

