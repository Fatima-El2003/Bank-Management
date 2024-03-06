#ifndef CREDITIMMOBILIER_H
#define CREDITIMMOBILIER_H
#include"credit.h"
#include <cmath>

class creditImmobilier :public credit{
    float TAEG;
    float taux;

public:
    creditImmobilier();
    creditImmobilier(float,float);
    ~creditImmobilier(){}
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
};

#endif // CREDITIMMOBILIER_H
