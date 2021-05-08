#include "patient.h"
#include <QDebug>
#include <QDate>
#include <qmessagebox.h>

Patient::Patient()
{
nom="";
prenom="";
sexe="";
lieu_de_residance="";
numero_telephone=0;
s_medecin="";
description="";
age=0;

}


Patient::Patient(QString nom,QString prenom,QString sexe,QString lieu_de_residance,int numero_telephone,QString s_medecin,QString description,int age)
{
  this->nom=nom;
  this->prenom=prenom;
  this->sexe=sexe;
  this->lieu_de_residance=lieu_de_residance;
  this->numero_telephone=numero_telephone;
  this->s_medecin=s_medecin;
  this->description=description;
  this->age=age;
}

QString Patient::get_nom(){return  nom;}
QString Patient::get_prenom(){return prenom;}
QString Patient::get_sexe(){return sexe;}
QString Patient::get_lr(){return lieu_de_residance;}
int Patient::get_tel(){return numero_telephone;}
QString Patient::get_s_medecin(){return s_medecin;}
QString Patient::get_description(){return description;}
int Patient::get_age(){return age;}



bool Patient::ajouter()
{
QSqlQuery query;
QString res= QString::number(numero_telephone);
QString res1= QString::number(age);


query.prepare("INSERT INTO patient (NOM, PRENOM, SEXE, LIEU_DE_RESIDANCE, NUMERO_TELEPHONE, S_MEDECIN, DESCRIPTION, AGE) "
                    "VALUES (:nom, :prenom, :sexe, :lieu_de_residance, :numero_telephone, :s_medecin, :description, :age)");

query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":sexe", sexe);
query.bindValue(":lieu_de_residance", lieu_de_residance);
query.bindValue(":numero_telephone", res);
query.bindValue(":s_medecin", s_medecin);
query.bindValue(":description", description);
query.bindValue(":age", res1);

return    query.exec();
}




QSqlQueryModel * Patient::afficher()

{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from patient order by NOM");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("SEXE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("LIEU_DE_RESIDANCE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMERO_TELEPHONE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("S_MEDECIN"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("DESCRIPTION"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("AGE"));

    return model;
}



bool Patient::supprimer(int num_tel)
{
    QSqlQuery query;
    QString res= QString::number(num_tel);
    query.prepare("DELETE from patient where NUMERO_TELEPHONE=:numero_telephone");
    query.bindValue(":numero_telephone",res);
    return    query.exec();

}


Patient Patient::getPatient(int numero_telephone)
{
    Patient *p = new Patient();

    QSqlQuery query;
    QString res= QString::number(numero_telephone);
    query.prepare("SELECT * from patient where NUMERO_TELEPHONE=:numero_telephone");
    query.bindValue(":numero_telephone",res);
    query.exec();
    while (query.next()) {

            p->setnom(query.value(0).toString());
            p->setprenom(query.value(1).toString());
            p->setsexe(query.value(2).toString());
            p->setlr(query.value(3).toString());
            p->settel(query.value(4).toInt());
            p->sets_medecin(query.value(5).toString());
            p->setdescription(query.value(6).toString());
            p->setage(query.value(7).toInt());

        }
    return    *p ;
}


void Patient::modifierPatient(int numero_telephone )
{
    QSqlQuery query;
    QString x= QString::number(numero_telephone);
    QString y= QString::number(age);


    query.prepare("UPDATE PATIENT  SET NOM=:nom, PRENOM=:prenom, SEXE=:sexe, LIEU_DE_RESIDANCE=:lieu_de_residance ,S_MEDECIN=:s_medecin ,DESCRIPTION=:description, AGE=:age where NUMERO_TELEPHONE =:numero_telephone ");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":sexe", sexe);
    query.bindValue(":lieu_de_residance", lieu_de_residance);
    query.bindValue(":numero_telephone", x);
    query.bindValue(":s_medecin", s_medecin);
    query.bindValue(":description", description);
    query.bindValue(":age", y);

    query.exec();

    if(query.exec())
    {
    QMessageBox::information(nullptr, QObject::tr("Modifier un patient"),
                      QObject::tr("Patient modifié.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier un patient"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}



QSqlQueryModel * Patient::afficherminmax()

{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT  MIN(age) as A_minimum,  MAX(age) as A_maximum FROM Patient");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("A_minimum"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("A_maximum"));

    return model;
}


QSqlQueryModel * Patient:: affichermoy()

{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT ROUND(AVG( Age), 2) as Moyenne_age FROM patient");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Moyenne_age"));
    return model;
}

QSqlQueryModel * Patient:: afficherspecstats()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT s_medecin,count(*) FROM patient group by s_medecin");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Specialite"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nbre_des_patients"));
    return model;
}
