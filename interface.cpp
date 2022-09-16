#include "interface.h"
#include "ui_interface.h"
#include "client.h"

#include<QPainter>
#include<QPdfWriter>
#include<QMediaPlayer>
#include <QMessageBox>
#include<QDesktopServices>

interface::interface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::interface)
{
    ui->setupUi(this);
    client client;
    ui->tabclient->setModel(client.afficher());//refresh
    ui->comboBox_2->setModel(client.afficher());
    ui->comboBox_ID_modifier->setModel(client.afficher());

    ui->leid_3->setValidator(new QIntValidator(0, 9999999, this));

    //ui->tabevenement_2->setModel(E.afficher());
}

interface::~interface()
{
    delete ui;
}

void interface::on_pushButton_ajouter_client_clicked()
{
    client c;
    bool test;
    int id= ui->lineEdit_1->text().toInt();
    QString nom= ui->lineEdit_2->text();
    QString prenom=ui->lineEdit_3->text();
    int num_telephone= ui->lineEdit_4->text().toInt();
    int cin= ui->lineEdit_5->text().toInt();
    QString email=ui->lineEdit_6->text();
    int age= ui->lineEdit_9->text().toInt();
        if(nom==""|| prenom==""||id==0||cin>99999999||num_telephone==0||c.testemail(email)==false||num_telephone>99999999||cin==0)
            {
                QMessageBox::critical(nullptr, QObject::tr("vide"),
                QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);
                test=false;

             }
        else{
        client p(id,nom,prenom,num_telephone,cin,email,age);
         test=p.ajouter();}

         if(test)
         {

             ui->tabclient->setModel(c.afficher());//refresh
             QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                               QObject::tr("client ajouté.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

             }
               else
                   QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                               QObject::tr("Erreur !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}


void interface::on_pushButton_rechercher_client_clicked()
{
    client client;
    int id;
    id=ui->lineEdit_13->text().toInt();


   bool test= true;
    if(test==(true))
    {
      ui->tabclient->setModel(client.rechercher(id));
}
}


void interface::on_pushButton_imprimer_clicked()
{
    QPdfWriter pdf("C:/Users/mehdi/Desktop/pdf2A/Pdf.pdf");
    QPainter painter(&pdf);
   int i = 4000;
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(800,900,"Liste Des Clients");
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(200,3300,"ID");
        painter.drawText(1700,3300,"NOM");
        painter.drawText(3200,3300,"PRENOM");
        painter.drawText(4900,3300,"NUMTEL");
        painter.drawText(6600,3300,"CIN");
        painter.drawText(8100,3300,"EMAIL");
        QSqlQuery query;
        query.prepare("select * from CLIENT");
        query.exec();
        while (query.next())
        {
            painter.drawText(200,i,query.value(0).toString());
            painter.drawText(1700,i,query.value(1).toString());
            painter.drawText(3200,i,query.value(2).toString());
            painter.drawText(4900,i,query.value(3).toString());
            painter.drawText(6600,i,query.value(4).toString());
            painter.drawText(8100,i,query.value(5).toString());
           i = i + 500;
        }
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/mehdi/Desktop/pdf2A/Pdf.pdf"));
                painter.end();
            }
            if (reponse == QMessageBox::No)
            {
                 painter.end();
           }
}


void interface::on_pushButton_modifier_client_clicked()
{
    client client;
    int id= ui->comboBox_ID_modifier->currentText().toInt();
    int num_telephone= ui->lineEdit_21->text().toInt();
    int age= ui->lineEdit_22->text().toInt();


  bool test=client.modifier( id,num_telephone,age );

  if (test)
     {
         ui->comboBox_ID_modifier->setModel(client.afficher());
         ui->tabclient->setModel(client.afficher());//refresh
         QMessageBox::information(nullptr, QObject::tr("Modifier un client"),
                     QObject::tr("Personnel modifié.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Modifier un client"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}


void interface::on_pushButton_supprimer_client_clicked()
{
    client client;
    int res=ui->comboBox_2->currentText().toInt();
            bool test=client.supprimer(res);

            if(test)
            {   ui->comboBox_2->setModel(client.afficher());
                ui->tabclient->setModel(client.afficher());
                QMessageBox::information(nullptr, QObject::tr("Supprimer une client"),
                            QObject::tr("personnel supprimé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}


void interface::on_pushButton_rechercher_evenements_clicked()
{

}


void interface::on_pbimprim_2_clicked()
{

}


void interface::on_pbajouter1_2_clicked()
{

}


void interface::on_pbmodif1_2_clicked()
{

}


void interface::on_pbsupp1_2_clicked()
{

}

