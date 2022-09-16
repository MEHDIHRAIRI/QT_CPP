#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_ajouter_client_clicked();

    void on_pushButton_rechercher_client_clicked();

    void on_radioButton_tri_client_clicked();

    void on_radioButton_tri_client_2_clicked();

    void on_pushButton_imprimer_clicked();

    void on_pushButton_modifier_client_clicked();

    void on_pushButton_supprimer_client_clicked();

    void on_pbmodif1_2_clicked();

    void on_pbimprim_2_clicked();

    void on_pushButton_rechercher_evenements_clicked();

    void on_pbajouter1_2_clicked();

    void on_pbsupp1_2_clicked();

    void on_pbimprim_3_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
