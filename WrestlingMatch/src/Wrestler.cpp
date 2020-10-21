#include <iostream>
#include <time.h>
#include <random>
#include "../include/Wrestler.h"

using namespace std;
#define MEAN_ABILITYSCORE 100
#define STANDARD_DEVIATION_ABLITY 25

#define MEAN_WEIGHT 170
#define STANDARD_DEVIATION_WEIGHT 20


Wrestler::Wrestler(){
  id=0;
  default_random_engine generator(time(NULL));
  normal_distribution<double> abilityDist(MEAN_ABILITYSCORE,STANDARD_DEVIATION_ABLITY);
  normal_distribution<double> weigthDist (MEAN_WEIGHT,STANDARD_DEVIATION_WEIGHT);
  abilityScore=abilityDist(generator);
  weight=(int)weigthDist(generator);
  
}

Wrestler::Wrestler(int i){
  id=i;
  default_random_engine generator(time(NULL));
  normal_distribution<double> abilityDist(MEAN_ABILITYSCORE,STANDARD_DEVIATION_ABLITY);
  normal_distribution<double> weigthDist (MEAN_WEIGHT,STANDARD_DEVIATION_WEIGHT);
  abilityScore=abilityDist(generator);
  weight=(int)weigthDist(generator);
}

int Wrestler::getWeight(){return weight;}
int Wrestler::getId(){return id;}
double Wrestler::getAbilityScore() const {return abilityScore;}

void Wrestler::setWeight(int w){weight=w;}
void Wrestler::setId(int i){id=i;}
void Wrestler::setAbilityScore(double a){abilityScore=a;}



int Wrestler::bout(const Wrestler& rhs){
  default_random_engine generator(time(NULL));
  normal_distribution<double> d1(this->getAbilityScore(),STANDARD_DEVIATION_ABLITY);
  normal_distribution<double> d2(rhs.abilityScore,STANDARD_DEVIATION_ABLITY);

  double r=d1(generator)-d2(generator);

  if(r>21.0)return 6;
  else if((r>15.0)&&(r<=21.0))return 5;
  else if ((r>8.0)&&(r<=15.0))return 4;
  else if ((r<=8.0)&&(r>0.0)) return 3;

  else if ((r>=-8.0)&&(r<0.0))return -3;
  else if ((r<-8.0)&&(r>=-15.0))return -4;
  else if ((r<-15.0)&&(r>=-21.0))return -5;
  else if ((r<-21.0)) return -6;
  else return 0;

}
