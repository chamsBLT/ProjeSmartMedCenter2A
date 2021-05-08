#ifndef PATIENT_H
#define PATIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class Patient
{public:
    Patient();
    Patient(QString,QString,QString,QString,int,QString,QString,int);
    QString get_nom();
    QString get_prenom();
    QString get_sexe();
    QString get_lr();
    int get_tel();
    QString get_s_medecin();
    QString get_description();
    int get_age();

    void setnom(QString A){nom=A;}
    void setprenom(QString A){prenom=A;}
    void setsexe(QString A){sexe=A;}
    void setlr(QString A){lieu_de_residance=A;}
    void settel(int A){numero_telephone=A;}
    void sets_medecin(QString A){s_medecin=A;}
    void setdescription(QString A){description=A;}
    void setage(int A){age=A;}



    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    Patient getPatient (int);
    void modifierPatient(int);
    QSqlQueryModel * afficherminmax();
    QSqlQueryModel * affichermoy();
    QSqlQueryModel * afficherspecstats();
private:
    QString nom,prenom,lieu_de_residance,s_medecin,description,sexe;
    int numero_telephone,age;

};

#endif // PATIENT_H
