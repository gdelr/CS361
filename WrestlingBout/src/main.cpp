#include <iostream>
#include <time.h>
#include <random>
#include "../include/Wrestler.h"

using namespace std;

int main(){
  Wrestler w1,w2;

  default_random_engine generator(time(NULL));
  normal_distribution<double> distribution(100,25);

  w1.setWeight(150);
  w2.setWeight(150);

  w1.setAbilityScore(distribution(generator));
  w2.setAbilityScore(distribution(generator));

  cout<<"w1 abilityScore is "<<w1.getAbilityScore()<<endl;
  cout<<"w2 abilityScore is "<<w2.getAbilityScore()<<endl;

  cout<<"The reuslt of the bout was: "<<w1.bout(w2)<<endl;


  
  return 0;
}
