#include "specialite_med.h"

specialite_med::specialite_med()
{

speci_med="";

}


specialite_med::specialite_med(QString speci_med)
{
    this->speci_med=speci_med;

}

QString specialite_med::get_smed(){return  speci_med;}


bool specialite_med::ajouters()
{

    QSqlQuery query;
    query.prepare("INSERT INTO CONSULTATION_PRIMERE (S_MEDECIN) "
                        "VALUES (:speci_med)");

    query.bindValue(":speci_med", speci_med);
    return    query.exec();

}


QSqlQueryModel * specialite_med::affichers()

{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CONSULTATION_PRIMERE order by S_medecin");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("S_MEDECIN"));

return model;
}

bool specialite_med::supprimers(QString speci_med )
{
    QSqlQuery query;
    query.prepare("DELETE from CONSULTATION_PRIMERE where S_MEDECIN=:speci_med");
    query.bindValue(":speci_med",speci_med);
    return    query.exec();

}

