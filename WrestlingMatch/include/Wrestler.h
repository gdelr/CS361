#ifndef WRESTLER_H
#define WRESTLER_H

class Wrestler {
  int weight;
  int id;
  double abilityScore;
public:
  Wrestler();
  Wrestler(int i);

  int getWeight();
  int getId();
  double getAbilityScore() const;

  void setWeight(int w);
  void setId(int i);
  void setAbilityScore(double a);


  int bout(const Wrestler& rhs);
  };

#endif 
