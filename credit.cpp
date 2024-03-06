#include "credit.h"
credit::credit(){
    this->codeCredit=0;
    this->montant=0;
    this->dureeEmprunt=0;
    this->j=0;
    this->m=0;
    this->y=0;
}
credit::credit(int a,float b,int c,int d,int e,int f){
    this->codeCredit=a;
    this->montant=b;
    this->dureeEmprunt=c;
    this->j=d;
    this->m=e;
    this->y=f;
}
