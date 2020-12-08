#include <iostream>
#include <random>
#include <list>
#include <string>
#include <fstream>
using namespace std;
//this algorithm has a computational complexity of O(N^3)



//This function takes a character array and retunrs a list of all possible substrings 
//O(N^3)

list<string> subString(char str[],int n){
  list<string> listOfSubStrings;
  string temp="";
  for(int len=1;len<=n;len++){
    for(int i=0;i<=n-len;i++){
      int j=i+len-1;
      for(int k=i;k<=j;k++){
	temp+=str[k];
      }
      listOfSubStrings.push_back(temp);
      temp="";
    }
  }
  return listOfSubStrings;
}

//This function takes a charater and a number
//It returns a list of strings of that character from 1-n
//sampel output <"a","aa",..."a...a">
//O(n^2)
list<string> genCharList(int letter,int n){
  list<string> charList;
  string temp="";
  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      temp+=letter;
    }
   charList.push_back(temp);
   temp="";
  }
  return charList;
}


int main(){
  char str[]="abcdefghijklmnopqrstuvwxyz";

  //O(n^3)
  list<string> alphabetSubStringList=subString(str,26);
  list<string> sol;

  list<string>::iterator it;
  list<string>::iterator jt;
  list<list<string>>::iterator listOfListIterator;
  
  default_random_engine* gen;
  gen=new default_random_engine(time(NULL));
  uniform_int_distribution<int> distribution(97,122);
  
  cout<<"Enter how many random characters you want : ";
  int n;
  cin>>n;
  char randString[n];
  //O(n)
  int j=0;
  for(int i=0;i<n;i++){
    if(j==25){
      cout<<endl;
      j=0;
    }
    j++;
    char num=distribution(*gen);
    cout<<num<<" ";
    randString[i]=num;
  }
  cout<<endl;
  list<list<string>>listOfCharLists;
  //O(26N^2)
  for(int i=0;i<26;i++){
   list<string> temp=genCharList('a'+i,n);
   listOfCharLists.push_back(temp);
  }
  //O(N^3)
  list<string> randomSubStringList=subString(randString,n);

  //O(N^3)
  listOfListIterator=listOfCharLists.begin();
  while(listOfListIterator!=listOfCharLists.end()){
    it=(*listOfListIterator).begin();
    while(it!=(*listOfListIterator).end()){
      jt=randomSubStringList.begin();
      while(jt!=randomSubStringList.end()){
	if(((*jt)==(*it))&&(*jt).length()>1)
	  cout<<*it<<endl;
	jt++;
      }
      it++;
    }
    listOfListIterator++;
  }

  //O(N^2)
  it=alphabetSubStringList.begin();
  while(it!=alphabetSubStringList.end()){
    jt=randomSubStringList.begin();
    while(jt!=randomSubStringList.end()){
      if(((*jt)==(*it))&&(*jt).length()>1)
	cout<<*it<<endl;
      jt++;
    }
    it++;
  }
  return 0;
}
