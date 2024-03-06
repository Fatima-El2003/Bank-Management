#include "creditAconsomation.h"
#include "credit.h"

creditAconsomation::creditAconsomation(){
    TAEG=0;
    taux=0;
}
creditAconsomation::creditAconsomation(float a,float b){
  TAEG=a;
  taux=b;
}
