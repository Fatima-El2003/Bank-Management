#include"creditEtudiant.h"
#include "credit.h"

creditEtudiant::creditEtudiant(){
    TAEG=0;
    taux=0;
}
creditEtudiant::creditEtudiant(float a,float b){
  TAEG=a;
  taux=b;
}
