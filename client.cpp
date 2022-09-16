#include "client.h"
#include <QSqlQuery>
#include <QString>
#include <QTableView>


client::client()
{
    id=0;
    nom="";
    prenom="";
    num_telephone=0;
    cin=0;
    email="";
     age=0;
}
client::client(int id,QString nom,QString prenom, int num_telephone, int cin, QString email, int age)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->num_telephone=num_telephone;
    this->cin=cin;
    this->email=email;
    this->age=age;
}

int client:: get_id(){return id; }


bool client:: ajouter()
{
    QSqlQuery query;

    QString res= QString::number(id);
        QString res1= QString::number(num_telephone);
        QString res2= QString::number(cin);
        QString res3= QString::number(age);
    query.prepare("INSERT INTO CLIENT (ID,NOM,PRENOM,NUMTEL,CIN,EMAIL,AGE) "
                        "VALUES ( :id,:nom,:prenom,:num_telephone,:cin,:email,:age)");
    query.bindValue(":id", res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":num_telephone", res1);
    query.bindValue(":cin",res2);
    query.bindValue(":email",email);

    query.bindValue(":age",res3);


    return    query.exec();
    }

QSqlQueryModel *client::afficher()
{QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM CLIENT order by type  ");
    model->setQuery("SELECT* FROM CLIENT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMTEL"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
model->setHeaderData(6,Qt::Horizontal, QObject::tr("AGE"));


    return model;
}
bool client::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from CLIENT where ID = :id ");
    query.bindValue(":id", id);
    return    query.exec();
}

bool client:: modifier(int id ,int num_telephone ,int age)
{QSqlQuery query;
    QString res= QString::number(num_telephone);
    QString res2= QString::number(id);
   QString res1= QString::number(age);
         query.prepare("UPDATE client set ID=:id,NUMTEL=:num_telephone,AGE=:age where ID= :id ");
         query.bindValue(":id", res2);
         query.bindValue(":num_telephone", res);
          query.bindValue(":age", res1);

        return    query.exec();

}



QSqlQueryModel * client::rechercher(int id)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from CLIENT where ID =:id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

        return model;
   }


QSqlQueryModel * client::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CLIENT order by ID asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

    return model;
}

QSqlQueryModel * client::afficher_tri_2()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CLIENT order by AGE asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("AGE"));

    return model;
}


QSqlQueryModel * client::afficher_email()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select EMAIL from CLIENT   ");
    return model;
}
bool client::testemail(QString email){
    int test=0;
    for(int i = 0; i < email.size(); i++) {
if(email[i]=="@")
{test++;

}}
    for(int i = 0; i < email.size(); i++) {
if((test==1)&&(email[i]=="."))
{if(email.size()>i+1)
    return true;
}}
return false;}





QSqlQueryModel *client::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM CLIENT " +cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMTEL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("AGE"));



    return model;
}


