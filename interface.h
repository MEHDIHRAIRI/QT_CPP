#ifndef INTERFACE_H
#define INTERFACE_H

#include <QDialog>

namespace Ui {
class interface;
}

class interface : public QDialog
{
    Q_OBJECT

public:
    explicit interface(QWidget *parent = nullptr);
    ~interface();

private slots:
    void on_pushButton_ajouter_client_clicked();

    void on_pushButton_rechercher_client_clicked();

    void on_pushButton_imprimer_clicked();

    void on_pushButton_modifier_client_clicked();

    void on_pushButton_supprimer_client_clicked();

    void on_pushButton_rechercher_evenements_clicked();

    void on_pbimprim_2_clicked();

    void on_pbajouter1_2_clicked();

    void on_pbmodif1_2_clicked();

    void on_pbsupp1_2_clicked();

private:
    Ui::interface *ui;
};

#endif // INTERFACE_H
