#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"client.h"
#include"creditImmobilier.h"
#include "creditAconsomation.h"
#include"creditEtudiant.h"
#include"rembourserEnLigne.h"


extern client c;
extern creditImmobilier cr;
extern creditAconsomation cr2;
extern creditEtudiant cr3;
extern rembourserEnLigne rm;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_1_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_5_clicked();


    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
