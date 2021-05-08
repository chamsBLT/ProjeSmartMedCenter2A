#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "patient.h"
#include <QMessageBox>
#include "specialites.h"
#include "statistiques.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabpatient->setModel(tmppatient.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Ajouter_patient_clicked()
{

    QString nom = ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_Prenom->text();
    QString sexe= ui->lineEdit_Sexe->text();
    QString lieu_de_residance = ui-> lineEdit_LR->text();
    int numero_telephone = ui->lineEdit_tel->text().toInt();
    QString s_medecin = ui->lineEdit_s_med->text();
    QString description = ui->lineEdit_Desc->text();
    int age = ui->lineEdit_age->text().toInt();




    Patient p(nom,prenom,sexe,lieu_de_residance,numero_telephone,s_medecin,description,age);
    bool test=p.ajouter();
    if(test)
    {ui->tabpatient->setModel(tmppatient.afficher());
    QMessageBox::information(nullptr, QObject::tr("Ajouter un patient"),
                      QObject::tr("Patient ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un patient"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_supprimerP_clicked()
{
    int numero_telephone = ui->lineEdit_Stel->text().toInt();
    bool test=tmppatient.supprimer(numero_telephone);
    if(test)
    {ui->tabpatient->setModel(tmppatient.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un patient"),
                    QObject::tr("Patient supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un patient"),
                    QObject::tr("Patient inrouvable. !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_trouver_clicked()
{
    QString numero_telephone = ui->num_modif->text();
    Patient *p=new Patient();
    *p=p->getPatient(ui->num_modif->text().toInt());
    QString age= QString::number(p->get_age());
    QString num= QString::number(p->get_tel());

    ui->nom_new->setText(p->get_nom());
    ui->prenom_new->setText(p->get_prenom());
    ui->age_new->setText(age);
    ui->sexe_new->setText(p->get_sexe());
    ui->lr_new->setText(p->get_lr());
    ui->num_new->setText(num);
    ui->s_medecin_new->setText(p->get_s_medecin());
    ui->description_new->setText(p->get_description());

}

void MainWindow::on_modifier_clicked()
{
    QString nom = ui->nom_new->text();
    QString prenom= ui->prenom_new->text();
    QString sexe= ui->sexe_new->text();
    QString lieu_de_residance = ui-> lr_new->text();
    int numero_telephone = ui->num_new->text().toInt();
    QString s_medecin = ui->s_medecin_new->text();
    QString description = ui->description_new->text();
    int age = ui->age_new->text().toInt();

    Patient *p = new Patient(nom,prenom,sexe,lieu_de_residance,numero_telephone,s_medecin,description,age);
    p->modifierPatient(numero_telephone);
    ui->tabpatient->setModel(tmppatient.afficher());
}




void MainWindow::on_g_specialites_clicked()
{
    specialites spes;
    spes.setModal(true);
    spes.exec();
}

void MainWindow::on_push_stats_clicked()
{
    Statistiques stats;
    stats.setModal(true);
    stats.exec();
}
