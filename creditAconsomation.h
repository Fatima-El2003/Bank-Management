#ifndef CREDITACONSOMATION_H
#define CREDITACONSOMATION_H

#include "credit.h"
#include <cmath>


class creditAconsomation: public credit{
    float TAEG;
    float taux;

public:
    creditAconsomation();
    creditAconsomation(float,float);
    ~creditAconsomation(){}
    float getTAEG(){
        return TAEG;
    }

    float gettaux(){
        return taux;
    }

    void setTAEG(float s){
        TAEG=s;
    }

    void settaux(float s){
        taux=s;
    }

    int nbrMentualite(){
        return 12*(this->getdureeEmprunt());
    }

    float calculerMensualite(){
        int m;
        m=this->nbrMentualite();
        float r;
        r=(this->getmontant()*TAEG*pow((1+TAEG),m))/(pow(1+TAEG,m)-1);

        return r;
    }
    void afficher();

};

#endif // CREDITACONSOMATION_H
