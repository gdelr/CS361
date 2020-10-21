#include <iostream>
#include <time.h>
#include <random>
#include <queue>
#include "../include/Wrestler.h"
#include "../include/Team.h"

using namespace std;

int main(){

  Team t1(300);
  Team t2(400);

  t1.match(t2);

  cout<<t1.getTeamScore()<<endl;
  cout<<t2.getTeamScore()<<endl;
  
  
  return 0;
  
}
