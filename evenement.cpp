#include "evenement.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>

evenement::evenement()
{
    id =0;
    titre= "";
    lieu= "";
    date_eve= "";

}
evenement::evenement(int id, QString titre,QString lieu,QString date_eve)
{
    this->id = id;
    this->titre = titre;
    this->lieu = lieu;
    this->date_eve = date_eve;

}
int     evenement:: getid(){return id;}
QString evenement:: gettitre(){return titre ;}
QString evenement:: getlieu(){return lieu ;}
QString evenement:: getdate_eve(){return date_eve ;}

void evenement::setid(int id ){this->id=id ;}
void evenement::settitre(QString titre){this->titre=titre;}
void evenement::setlieu(QString lieu){this->lieu=lieu;}
void evenement::setdate_eve(QString date_eve){this->date_eve=date_eve;}



bool evenement::ajouter()
{

    QSqlQuery query;
    query.prepare("INSERT INTO evenement (id, titre, lieu, date_eve ) "
                  "VALUES (:id, :titre, :lieu, :date_eve)");
    query.bindValue(":id", id);
    query.bindValue(":titre", titre);
    query.bindValue(":lieu", lieu);
    query.bindValue(":date_eve", date_eve);

    return query.exec();

}

bool evenement ::supprimer(int id)
{

    QSqlQuery query;

    query.prepare("Delete from evenement where id=:id ");

    query.bindValue(":id",id);

    return query.exec();


}
bool evenement ::modifier(int id )
{
    QSqlQuery query;

    query.prepare("UPDATE evenement SET id=:id ,titre=:titre, lieu=:lieu, date_eve=:date_eve where id=:id");
    query.bindValue(":id", id);
    query.bindValue(":titre", titre);
    query.bindValue(":lieu", lieu);
    query.bindValue(":date_eve", date_eve);

    return query.exec();
 }
QSqlQueryModel* evenement::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

        model->setQuery("SELECT* FROM evenement");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("titre"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("lieu"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_eve"));

  return model ;
}
QSqlQueryModel *evenement::afficher4()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM evenement order by type  ");
    model->setQuery("SELECT* FROM evenement");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("lieu"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_eve"));
    return  model;
}

QSqlQueryModel * evenement::rechercher(int id)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from evenement where id =:id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));

        return model;
   }


