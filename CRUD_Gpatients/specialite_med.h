#ifndef SPECIALITE_MED_H
#define SPECIALITE_MED_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class specialite_med
{
public:
    specialite_med();
    specialite_med(QString);
    QString get_smed();

    bool ajouters();
    QSqlQueryModel * affichers();
    bool supprimers(QString);

private:
    QString speci_med;

};

#endif // SPECIALITE_MED_H
