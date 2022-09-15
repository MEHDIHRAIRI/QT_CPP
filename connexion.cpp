#include "connexion.h"
#include "QSqlDatabase"
Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("mahdi");
db.setPassword("0606");
if (db.open())
    test=true;
return  test;
}
void Connexion::fermerConnexion()
{db.close();}
