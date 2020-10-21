#include <iostream>
#include <time.h>
#include <random>
#include <chrono>
#include <thread>
#include <queue>
#include <vector>
#include <stdlib.h>
#include "../include/Team.h"
#include "../include/Wrestler.h"

using namespace std;

#define MEAN_WRESTLERS 60
#define STANDARD_DEVIATION_TEAM 10

Team::Team(){
  
  teamId=0;
  for(int i=0;i<=13;i++){
    priority_queue<Wrestler *,vector<Wrestler*>,comparator> wrPQ;
    Wrestler* wPTR=new Wrestler(teamId+i);
    wrPQ.push(wPTR);
    school.push_back(wrPQ);
  }
}

Team::Team(int i){
  teamId=i;
  default_random_engine generator(time(NULL));
  normal_distribution<double> teamDist(MEAN_WRESTLERS,STANDARD_DEVIATION_TEAM);
  teamSize=(int)teamDist(generator);
  cout<<"team seize: "<<teamSize<<endl;
  Wrestler* wrPTR;
  for(int i=0;i<=13;i++){
    priority_queue<Wrestler *,vector<Wrestler*>,comparator> wrPQ;
    school.push_back(wrPQ);
    
  }
  
  for(int i=0;i<=teamSize;i++){
    this_thread::sleep_for(chrono::milliseconds(1000));
    wrPTR=new Wrestler(teamId+i);
    addWrestler(wrPTR);
  }
}

void Team::display(){
  cout<<"Team "<<teamId<<endl;
  it=school.begin();
  int i=0;
  while(it!=school.end()){
    cout<<"Weight Class "<<i<<":"<<endl;
    if((*it).size()==0){i++;it++;continue;}
    while(!(*it).empty()){
      cout<<"\t["<<(*it).top()->getWeight()
	  <<" - "<<(*it).top()->getAbilityScore()<<"]";
      (*it).pop();
    }
    cout<<endl;
    it++;
    i++;
  }
}

void Team::addWrestler(Wrestler* wr){
  int w=(*wr).getWeight();
  it=school.begin();
  if((w<106)){
    (*it).push(wr);
  }
  else if((w>=106)&&(w<113)){
    it++;
    (*it).push(wr);
  }
  else if((w>=113)&&(w<120)){
    it++;it++;
    (*it).push(wr);
  }
  else if((w>=120)&&(w<126)){
    it++;it++;it++;
    (*it).push(wr);
  }
  else if((w>=126)&&(w<132)){
    it++;it++;it++;it++;
    (*it).push(wr);
  }
  else if((w>=132)&&(w<138)){
    it++;it++;it++;it++;it++;
    (*it).push(wr);
  }
  else if((w>=138)&&(w<145)){
    it++;it++;it++;it++;it++;it++;
    (*it).push(wr);
  }
  else if((w>=145)&&(w<152)){
    it++;it++;it++;it++;it++;it++;it++;
    (*it).push(wr);
  }
  else if((w>=152)&&(w<160)){
    it++;it++;it++;it++;it++;it++;it++;it++;
    (*it).push(wr);
  }
  else if((w>=160)&&(w<170)){
    it++;it++;it++;it++;it++;it++;it++;it++;it++;
    (*it).push(wr);
  }
  else if((w>=170)&&(w<182)){
    it++;it++;it++;it++;it++;it++;it++;it++;it++;it++;
    (*it).push(wr);
  }
  else if((w>=182)&&(w<195)){
    it++;it++;it++;it++;it++;it++;it++;it++;it++;it++;it++;
    (*it).push(wr);
  }
  else if((w>=195)){
    it++;it++;it++;it++;it++;it++;it++;it++;it++;it++;it++;it++;
    (*it).push(wr);
  }
}

Wrestler* Team::getWrestler(int wc){
  wc--;
  it=school.begin();
  for(int i=0;i<=wc;i++){
    it++;
  }
  if((*it).size()>0){return (*it).top();}
  return NULL;
}

void Team::match(Team& rhs){
  int result;
  Wrestler* l;
  Wrestler* r;
  for(int i=0;i<=13;i++){
    l=getWrestler(i);
    r=rhs.getWrestler(i);
    if(l==NULL){
      rhs.setTeamScore(rhs.getTeamScore()+3);
      rhs.setNumWins(rhs.getNumWins()+1);
      numLoss--;
      continue;
    }
    else if(r==NULL){
      teamScore+=3;
      numWins++;
      rhs.setNumLoss(rhs.getNumLoss()+1);
      continue;
    }
    else if((r==NULL)&&(l==NULL)){continue;}
    result=l->bout(*r);
    if(result>0){
      teamScore+=abs(result);
      numWins++;
      rhs.setNumLoss(rhs.getNumLoss()+1);
    }
    else{
      rhs.setTeamScore(rhs.getTeamScore()+abs(result));
      rhs.setNumWins(rhs.getNumWins()+1);
      numLoss--;
    }
  }
}


