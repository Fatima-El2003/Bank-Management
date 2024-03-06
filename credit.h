#ifndef CREDIT_H
#define CREDIT_H

class credit{
  int codeCredit;
  float montant;
  int dureeEmprunt;
  int j;
  int m;
  int y;

public:
  credit();
  credit(int,float,int,int,int,int);
  ~credit(){}

  int getcodeCredit(){
      return codeCredit;
  }
  int getdureeEmprunt(){
      return dureeEmprunt;
  }
  float getmontant(){
      return montant;
  }
  int getj(){
      return j;
  }
  int getm(){
      return m;
  }
  int gety(){
      return y;
  }

  void setcodeCredit(int c){
      codeCredit=c;
  }
  void setdureeEmprunt(int c){
      dureeEmprunt=c;
  }
  void setmontant(float c){
      montant=c;
  }
  void setj(int c){
      j=c;
  }
  void setm(int c){
      m=c;
  }
  void sety(int c){
      y=c;
  }

};

#endif // CREDIT_H
