#ifndef EVENEMENT_H
#define EVENEMENT_H


#include <QString>
#include <QSqlQueryModel>

class evenement
{
public:
    evenement();
    evenement(int,QString,QString,QString);
    int getid();
    QString gettitre();
    QString getlieu();
    QString getdate_eve();

    void setid(int);
    void settitre(QString);
    void setlieu(QString);
    void setdate_eve(QString);


    bool ajouter();
    QSqlQueryModel*  afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* afficher4();
    QSqlQueryModel * rechercher(int );

private :
    int id;
    QString titre,lieu,date_eve ;
};

#endif // EVENEMENT_H
