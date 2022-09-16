#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class client
{
public:
    client();
    client(int,QString,QString,int,int,QString,int);
    int get_id();
    int get_num_telephone();
    QString get_nom();
    QString get_prenom();
    QString get_email();
    int get_cin();
     int get_age();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_email();
    bool testemail(QString);
    bool supprimer(int);
    bool modifier(int,int,int);
    QSqlQueryModel * rechercher(int );
    QSqlQueryModel * afficher_tri();
    QSqlQueryModel * afficher_tri_2();

    QSqlQueryModel *displayClause(QString cls);



private:


int id,age;
QString nom;
QString prenom;
int num_telephone;
int cin;
QString email;

};

#endif // CLIENTL_H
