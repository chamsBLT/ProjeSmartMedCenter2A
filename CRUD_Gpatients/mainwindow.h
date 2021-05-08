#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "patient.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Ajouter_patient_clicked();

    void on_pushButton_supprimerP_clicked();

    void on_trouver_clicked();

    void on_modifier_clicked();

    void on_g_specialites_clicked();

    void on_push_stats_clicked();

private:
    Ui::MainWindow *ui;
    Patient tmppatient;
};

#endif // MAINWINDOW_H
