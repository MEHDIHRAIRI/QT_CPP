#include "mainwindow.h".h"
#include "connexion.h"

#include <QApplication>
#include <QMessageBox>
#include <QQuickView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QQuickView view;
    //QStringLiteral("qrc:/map.qml")
    view.setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.resize(1024, 768);
    view.show();
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
