#include "specialites.h"
#include "ui_specialites.h"
#include "specialite_med.h"
#include <QMessageBox>

specialites::specialites(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::specialites)
{
    ui->setupUi(this);
}

specialites::~specialites()
{
    delete ui;
}

void specialites::on_retour_mw_clicked()
{
    hide();
}

void specialites::on_ajouter_as_clicked()
{
    QString speci_med = ui->lineEdit_as->text();

    specialite_med s(speci_med);
    bool test1=s.ajouters();

    if(test1)
    {ui->tabspecialite->setModel(tmpspecialite.affichers());
    QMessageBox::information(nullptr, QObject::tr("Ajouter une spécialité"),
                      QObject::tr("Spécialité ajoutée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter une spécialité"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void specialites::on_supprimer_ss_clicked()
{
    QString speci_med = ui->lineEdit_ss->text();
    bool test2=tmpspecialite.supprimers(speci_med);
    if(test2)
    {ui->tabspecialite->setModel(tmpspecialite.affichers());
        QMessageBox::information(nullptr, QObject::tr("Supprimer une spécialité"),
                    QObject::tr("Spécialité supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une spécialité"),
                    QObject::tr("Spécialité introuvable. !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
