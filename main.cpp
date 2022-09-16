#include "mainwindow.h".h"
#include "connexion.h"

#include <QApplication>
#include <QMessageBox>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow m;
    Connexion c;
       bool test=c.ouvrirConnexion();
       if(test)
       {m.show();
           QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("welcome.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
   }
   else
           QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                       QObject::tr("connection failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();
}
