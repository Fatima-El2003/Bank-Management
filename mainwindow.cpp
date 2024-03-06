#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"client.h"
#include "credit.h"
#include <QMessageBox>
#include <string>

using namespace std;

client c;
creditImmobilier cr;
creditAconsomation cr2;
creditEtudiant cr3;
rembourserEnLigne rm;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(8);
}


void MainWindow::on_pushButton_1_clicked()
{
     QString fname=ui->lineEdit_11->text();
     QString lname=ui->lineEdit_22->text();
     QString age=ui->lineEdit_33->text();
     QString cin=ui->lineEdit_44->text();
     QString y=ui->lineEdit_57->text();
     QString m=ui->lineEdit_56->text();
     QString d=ui->lineEdit_55->text();
     QString pays=ui->lineEdit_66->text();
     QString adresse=ui->lineEdit_77->text();
     QString sexe=ui->radioButton_2->text();

     c.setnom(fname.toStdString());
     c.setprenom(lname.toStdString());
     c.setage(age.toInt());
     c.setCIN(cin.toStdString());
     c.setannee(y.toInt());
     c.setmois(m.toInt());
     c.setjour(d.toInt());
     c.setpays(pays.toStdString());
     c.setadre(adresse.toStdString());
     c.setsexe(sexe.toStdString());

     if(c.getnom()==""||c.getprenom()==""||c.getage()==0||c.getCIN()==""||c.getannee()==0||c.getamois()==0||c.getjour()==0||c.getpays()==""||c.getadres()==""||c.getsexe()==""){
     QMessageBox::warning(this,"checkEmpty","please fill all the information");
     }else if(c.getage()<18){
     QMessageBox::about(this,"checkAge","the Age < 18 so you can't demande a credit");
         ui->lineEdit_11->setText("");
         ui->lineEdit_22->setText("");
         ui->lineEdit_33->setText("");
         ui->lineEdit_44->setText("");
         ui->lineEdit_57->setText("");
         ui->lineEdit_56->setText("");
         ui->lineEdit_55->setText("");
         ui->lineEdit_66->setText("");
         ui->lineEdit_77->setText("");

     ui->stackedWidget->setCurrentIndex(11);
     }else{
         QMessageBox::about(this,"checkAge","everything is good");
         ui->stackedWidget->setCurrentIndex(1);
     }


}


void MainWindow::on_toolButton_3_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_toolButton_4_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_toolButton_5_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}




void MainWindow::on_pushButton_5_clicked()
{

    QString revenuM=ui->lineEdit_9->text();
    QString profession=ui->lineEdit_10->text();
    QString situationF=ui->lineEdit_12->text();
    QString revenuC=ui->lineEdit_13->text();
    QString nbrE=ui->lineEdit_15->text();
    QString durree=ui->lineEdit_18->text();
    QString montant=ui->lineEdit_28->text();
    QString jour=ui->lineEdit_29->text();
    QString mois=ui->lineEdit_30->text();
    QString annee=ui->lineEdit_31->text();

    static int i=0;

    c.setrevenuM(revenuM.toFloat());
    c.setprofession(profession.toStdString());
    c.setrevenuC(revenuC.toFloat());
    c.setnbrE(nbrE.toInt());
    c.setsituationfamiliale(situationF.toStdString());
    cr2.setdureeEmprunt(durree.toInt());
    cr2.setcodeCredit(i);
       i++;
    cr2.setmontant(montant.toFloat());
    cr2.setj(jour.toInt());
    cr2.setm(mois.toInt());
    cr2.sety(annee.toInt());
    cr2.settaux(7.5);
    float taeg=7.5/(100*12);
    cr2.setTAEG(taeg);

    if(c.getrevenuM()==0.0||c.getprofession()==""||c.getrevenuC()==0.0||c.getsituationfamiliale()==""||c.getnbrE()==0||cr2.getmontant()==0.0||cr2.getdureeEmprunt()==0||cr2.gety()==0||cr2.getm()==0||cr2.getj()==0){
       QMessageBox::warning(this,"checkEmpty","please fill all the information");
    }else if((c.getrevenuM()+c.getrevenuC())<100){
        QMessageBox::warning(this,"checkRevenu","you don't have enough money !!!");
            ui->lineEdit_1->setText("");
            ui->lineEdit_2->setText("");
            ui->lineEdit_3->setText("");
            ui->lineEdit_7->setText("");
            ui->lineEdit_14->setText("");

    ui->stackedWidget->setCurrentIndex(1);
    }else if(!((cr2.getmontant()<10000&&cr2.getdureeEmprunt()==12)||(cr2.getmontant()>10000&&cr2.getmontant()<20000&&cr2.getdureeEmprunt()==24)||(cr2.getmontant()>20000&&cr2.getmontant()<40000&&cr2.getdureeEmprunt()==36)||(cr2.getmontant()>40000&&cr2.getmontant()<60000&&cr2.getdureeEmprunt()==48)||(cr2.getmontant()>60000&&cr2.getmontant()<100000&&cr2.getdureeEmprunt()==72))){

             QMessageBox::warning(this,"checkDureeEtMontant","il faut changer le type d'emprunt !!!");
                 ui->lineEdit_1->setText("");
                 ui->lineEdit_2->setText("");
                 ui->lineEdit_3->setText("");
                 ui->lineEdit_7->setText("");
                 ui->lineEdit_14->setText("");

            ui->stackedWidget->setCurrentIndex(4);

    }else{
        QMessageBox::about(this,"check","everything is good");
        ui->stackedWidget->setCurrentIndex(6);
        ui->label_42->setText(QString::fromStdString(c.getnom()));
        ui->label_43->setText(QString::fromStdString(std::to_string(cr2.getmontant())));
        ui->label_44->setText(QString::fromStdString(std::to_string(cr2.getdureeEmprunt())));
        ui->label_45->setText(QString::fromStdString(std::to_string(cr2.calculerMensualite())));
        ui->label_46->setText(QString::fromStdString(std::to_string(cr2.gettaux())));
    }
}


void MainWindow::on_pushButton_4_clicked()
{

    QString revenuM=ui->lineEdit_4->text();
    QString nationa=ui->lineEdit_5->text();
    QString logm=ui->lineEdit_6->text();
    QString cne=ui->lineEdit_8->text();
    QString durree=ui->lineEdit_17->text();
    QString montant=ui->lineEdit_24->text();
    QString jour=ui->lineEdit_25->text();
    QString mois=ui->lineEdit_26->text();
    QString annee=ui->lineEdit_27->text();

    static int i=0;

    c.setrevenuM(revenuM.toFloat());
    c.setnationa(nationa.toStdString());
    c.setlogement(logm.toStdString());
    c.setcne(cne.toStdString());
    cr3.setdureeEmprunt(durree.toInt());
    cr3.setcodeCredit(i);
       i++;
    cr3.setmontant(montant.toFloat());
    cr3.setj(jour.toInt());
    cr3.setm(mois.toInt());
    cr3.sety(annee.toInt());
    cr3.settaux(2);
    float taeg=2/(100*12);
    cr3.setTAEG(taeg);

    if(c.getrevenuM()==0.0||c.getnationa()==""||c.getlogement()==""||c.getcne()==""||cr3.getmontant()==0.0||cr3.getdureeEmprunt()==0||cr3.gety()==0||cr3.getm()==0||cr3.getj()==0){
       QMessageBox::warning(this,"checkEmpty","please fill all the information");
    }else if((c.getrevenuM())<100){
    QMessageBox::warning(this,"checkRevenu","you don't have enough money !!!");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_8->setText("");
    ui->lineEdit_17->setText("");
     ui->lineEdit_24->setText("");
      ui->lineEdit_25->setText("");
       ui->lineEdit_26->setText("");
        ui->lineEdit_27->setText("");
    ui->stackedWidget->setCurrentIndex(1);
    }else if(cr3.getmontant()>250000){

        QMessageBox::warning(this,"checkDureeEtMontant","il faut changer le type d'emprunt !!!");
            ui->lineEdit_4->setText("");
            ui->lineEdit_5->setText("");
            ui->lineEdit_6->setText("");
            ui->lineEdit_8->setText("");
            ui->lineEdit_17->setText("");
            ui->lineEdit_24->setText("");
            ui->lineEdit_25->setText("");
            ui->lineEdit_26->setText("");
            ui->lineEdit_27->setText("");
       ui->stackedWidget->setCurrentIndex(3);

}else{
   QMessageBox::about(this,"check","everything is good");
   ui->stackedWidget->setCurrentIndex(7);
   ui->label_58->setText(QString::fromStdString(c.getnom()));
   ui->label_63->setText(QString::fromStdString(std::to_string(cr3.getmontant())));
   ui->label_64->setText(QString::fromStdString(std::to_string(cr3.getdureeEmprunt())));
   ui->label_65->setText(QString::fromStdString(std::to_string(cr3.calculerMensualite())));
   ui->label_66->setText(QString::fromStdString(std::to_string(cr3.gettaux())));

}
}


void MainWindow::on_pushButton_3_clicked()
{

        QString revenuM=ui->lineEdit_1->text();
        QString profession=ui->lineEdit_2->text();
        QString situationF=ui->lineEdit_3->text();
        QString revenuC=ui->lineEdit_7->text();
        QString nbrE=ui->lineEdit_14->text();
        QString durree=ui->lineEdit_16->text();
        QString montant=ui->lineEdit_19->text();
        QString jour=ui->lineEdit_20->text();
        QString mois=ui->lineEdit_21->text();
        QString annee=ui->lineEdit_23->text();

        static int i=0;

        c.setrevenuM(revenuM.toFloat());
        c.setprofession(profession.toStdString());
        c.setrevenuC(revenuC.toFloat());
        c.setnbrE(nbrE.toInt());
        c.setsituationfamiliale(situationF.toStdString());
        cr.setdureeEmprunt(durree.toInt());
        cr.setcodeCredit(i);
           i++;
        cr.setmontant(montant.toFloat());
        cr.setj(jour.toInt());
        cr.setm(mois.toInt());
        cr.sety(annee.toInt());
        cr.settaux(4.2);
        float taeg=4.2/(100*12);
        cr.setTAEG(taeg);

        if(c.getrevenuM()==0.0||c.getprofession()==""||c.getrevenuC()==0.0||c.getsituationfamiliale()==""||c.getnbrE()==0||cr.getmontant()==0.0||cr.getdureeEmprunt()==0||cr.gety()==0||cr.getm()==0||cr.getj()==0){
           QMessageBox::warning(this,"checkEmpty","please fill all the information");
        }else if((c.getrevenuM()+c.getrevenuC())<100){
            QMessageBox::warning(this,"checkRevenu","you don't have enough money !!!");
            ui->lineEdit_1->setText("");
            ui->lineEdit_2->setText("");
            ui->lineEdit_3->setText("");
            ui->lineEdit_7->setText("");
            ui->lineEdit_14->setText("");
             ui->lineEdit_16->setText("");
              ui->lineEdit_19->setText("");
               ui->lineEdit_20->setText("");
                ui->lineEdit_21->setText("");
                ui->lineEdit_23->setText("");

        ui->stackedWidget->setCurrentIndex(1);
        }else if((cr.getdureeEmprunt()>(25*12))||(cr.getmontant()>497828500.0)){

                 QMessageBox::warning(this,"checkDureeEtMontant","il faut changer le type d'emprunt !!!");
                 ui->lineEdit_1->setText("");
                 ui->lineEdit_2->setText("");
                 ui->lineEdit_3->setText("");
                 ui->lineEdit_7->setText("");
                 ui->lineEdit_14->setText("");
                  ui->lineEdit_16->setText("");
                   ui->lineEdit_19->setText("");
                    ui->lineEdit_20->setText("");
                     ui->lineEdit_21->setText("");
                     ui->lineEdit_23->setText("");
                ui->stackedWidget->setCurrentIndex(2);

        }else{
            QMessageBox::about(this,"check","everything is good");
            ui->stackedWidget->setCurrentIndex(5);
            ui->label_48->setText(QString::fromStdString(c.getnom()));
            ui->label_50->setText(QString::fromStdString(std::to_string(cr.getmontant())));
            ui->label_52->setText(QString::fromStdString(std::to_string(cr.getdureeEmprunt())));
            ui->label_54->setText(QString::fromStdString(std::to_string(cr.calculerMensualite())));
            ui->label_56->setText(QString::fromStdString(std::to_string(cr.gettaux())));
        }

}


void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}


void MainWindow::on_pushButton_12_clicked()
{
        ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_pushButton_13_clicked()
{


     ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);

}


void MainWindow::on_pushButton_14_clicked()
{
     ui->stackedWidget->setCurrentIndex(10);

    if(!(cr.gettaux()==0)){
        ui->label_84->setText(QString::fromStdString(std::to_string(rm.CalculeMontantRestantRom(cr.calculerMensualite(),cr.getdureeEmprunt()))));
        ui->label_83->setText(QString::fromStdString(std::to_string(cr.calculerMensualite())));
    }
    if(!(cr2.gettaux()==0)){
        ui->label_84->setText(QString::number(rm.CalculeMontantRestantRom(cr2.calculerMensualite(),cr2.getdureeEmprunt())));
        ui->label_83->setText(QString::number(cr2.calculerMensualite()));
    }
    if(!(cr3.gettaux()==0)){
        ui->label_84->setText(QString::number(rm.CalculeMontantRestantRom(cr3.calculerMensualite(),cr3.getdureeEmprunt())));
        ui->label_83->setText(QString::number(cr3.calculerMensualite()));
    }


}

