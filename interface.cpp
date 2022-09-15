#include "interface.h"
#include "ui_interface.h"

interface::interface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::interface)
{
    ui->setupUi(this);
}

interface::~interface()
{
    delete ui;
}

void interface::on_pushButton_ajouter_client_clicked()
{

}


void interface::on_pushButton_rechercher_client_clicked()
{

}


void interface::on_pushButton_imprimer_clicked()
{

}


void interface::on_pushButton_modifier_client_clicked()
{

}


void interface::on_pushButton_supprimer_client_clicked()
{

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

