#ifndef CLIENT_H
#define CLIENT_H
#include<string>
using namespace std;
class client{
string nom;
string prenom;
int annee;
int mois;
int jour;
int age;
string pays;
string adresse;
string profession;
string nationalite;
string sexe;
string situationfamiliale;
int nbrenfant;
float revenumensuel;
float revenucomplementaire;
string logement;
string CIN;
string cne;
public:
  //constructeur par defaut;
    client();
  //destructeur
    ~client();

  //getters
    string getnom(){
        return nom;
    }
    string getprenom(){
        return prenom;
    }
    int getannee(){
        return annee;
    }
    int getamois(){
        return mois ;
    }
    int getjour(){
        return jour ;
    }
    int getage(){
        return age;
    }

    int getnbrE(){
        return nbrenfant;
    }

    string getpays(){
        return pays;
    }
    string getnationa(){
        return nationalite;
    }
    string getCIN(){
        return CIN;
    }
    string getcne(){
        return cne;
    }
    string getprofession(){
        return profession;
    }
    string getsexe(){
        return sexe;
    }
    string getsituationfamiliale(){
        return situationfamiliale;
    }
    string getadres(){
        return adresse;
    }

    string getlogement(){
        return logement;
    }

    float getrevenuM(){
        return revenumensuel;
    }

    float getrevenuC(){
        return revenucomplementaire;
    }


    //setters
    void setnom(string s){
        nom=s;
    }
    void setprenom(string s){
        prenom=s;
    }
    void setannee(int a){
         annee=a;
    }
    void setmois(int m){
         mois=m ;
    }
    void setjour(int j){
         jour=j ;
    }
    void setage(int a){
         age=a;
    }
    void setpays(string n){
         pays=n;
    }
    void setprofession(string p){
        profession=p;
    }
    void setsexe(string s){
        sexe=s;
    }

    void setCIN(string s){
        CIN=s;
    }
    void setcne(string s){
        cne=s;
    }
   void setsituationfamiliale(string s){
        situationfamiliale=s;
    }
   void setnationa(string s){
        nationalite=s;
    }
   void setadre(string s){
        adresse=s;
    }

   void setrevenuM(float f){
        revenumensuel=f;
   }
   void setrevenuC(float f){
        revenucomplementaire=f;
   }
   void setlogement(string f){
        logement=f;
   }
   void setnbrE(int n){
      nbrenfant=n;
   }

};

#endif // CLIENT_H
