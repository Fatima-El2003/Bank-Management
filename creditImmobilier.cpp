#include"creditImmobilier.h"
#include "credit.h"

creditImmobilier::creditImmobilier(){
    TAEG=0;
    taux=0;
}
creditImmobilier::creditImmobilier(float a,float b){
  TAEG=a;
  taux=b;
}
