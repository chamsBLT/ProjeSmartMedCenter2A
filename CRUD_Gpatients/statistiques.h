#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include <QDialog>
#include "patient.h"

namespace Ui {
class Statistiques;
}

class Statistiques : public QDialog
{
    Q_OBJECT

public:
    explicit Statistiques(QWidget *parent = nullptr);
    ~Statistiques();

private slots:
    void on_retour_mw2_clicked();

    void on_minmax_clicked();

    void on_moyenne_clicked();

    void on_patientparspec_clicked();

private:
    Ui::Statistiques *ui;
    Patient tmppatient;
};

#endif // STATISTIQUES_H
