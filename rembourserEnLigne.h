#ifndef REMBOURSERENLIGNE_H
#define REMBOURSERENLIGNE_H
#include"rembourser.h"
class rembourserEnLigne: public rembourser{
 int codeBancaire;
public:
 rembourserEnLigne();
 ~rembourserEnLigne();
 int getcodeBancaire(){
     return codeBancaire;
 }
 void setcodeBancaire(int c ){
     codeBancaire=c;
 }

};

#endif // REMBOURSERENLIGNE_H
