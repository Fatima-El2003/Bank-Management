#ifndef REMBOURSER_H
#define REMBOURSER_H
#include"credit.h"
class rembourser{
float montant;
//date de payement;
int annee;
int mois;
int jour;
public:
 rembourser();
 ~rembourser();
 //getters
 float getmontant(){
     return montant;
    }
 int getannee(){
     return annee;
 }
 int getmois(){
     return mois;
 }
 int getjour(){
     return jour;
 }
//setters
 void setmontant(float m){
      montant=m;
    }
 void setannee(int a){
    annee=a;
 }
 void setmois(int m){
      mois=m;
 }
 void setjour(int j){
      jour=j;
 }
 float CalculeMontantRestantRom(float m,int d){
     return (m*d)-m;
 }
 void afficher();
};

#endif // REMBOURSER_H
