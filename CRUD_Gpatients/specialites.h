#ifndef SPECIALITES_H
#define SPECIALITES_H
#include "specialite_med.h"
#include <QDialog>

namespace Ui {
class specialites;
}

class specialites : public QDialog
{
    Q_OBJECT

public:
    explicit specialites(QWidget *parent = nullptr);
    ~specialites();

private slots:
    void on_retour_mw_clicked();

    void on_ajouter_as_clicked();

    void on_supprimer_ss_clicked();

private:
    Ui::specialites *ui;
    specialite_med tmpspecialite;

};

#endif // SPECIALITES_H
