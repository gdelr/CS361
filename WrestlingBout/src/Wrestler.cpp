#include <iostream>
#include <time.h>
#include <random>
#include "../include/Wrestler.h"

using namespace std;

Wrestler::Wrestler(){}

int Wrestler::getWeight(){return weight;}
int Wrestler::getId(){return id;}
double Wrestler::getAbilityScore(){return abilityScore;}

void Wrestler::setWeight(int w){weight=w;}
void Wrestler::setId(int i){id=i;}
void Wrestler::setAbilityScore(double a){abilityScore=a;}



double Wrestler::bout(const Wrestler& rhs){
  default_random_engine generator(time(NULL));
  normal_distribution<double> d1(this->getAbilityScore(),15);
  normal_distribution<double> d2(rhs.abilityScore,15);

  return d1(generator)-d2(generator);
}
