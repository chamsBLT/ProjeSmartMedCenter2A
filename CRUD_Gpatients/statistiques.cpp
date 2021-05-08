#include "statistiques.h"
#include "ui_statistiques.h"
#include "patient.h"

Statistiques::Statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistiques)
{
    ui->setupUi(this);
    ui->tableminmax->setModel(tmppatient.afficherminmax());
}

Statistiques::~Statistiques()
{
    delete ui;
}

void Statistiques::on_retour_mw2_clicked()
{
    hide();
}

void Statistiques::on_minmax_clicked()
{
    ui->tableminmax->setModel(tmppatient.afficherminmax());
}


void Statistiques::on_moyenne_clicked()
{
    ui->tablemoy->setModel(tmppatient.affichermoy());
}

void Statistiques::on_patientparspec_clicked()
{
    ui->tableocc->setModel(tmppatient.afficherspecstats());
}
