#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
class Set {
  private:
  string arraywords[100];
  string newarray[100];
  int arraycount[100];
  int newcountarray[100];
  int maxnum;
  int numwords;
  int numcount;
  int numlength;
  int countlength;
  
  public:
  Set();
  void AddSetWords(string text);
  void AddCount(int num);
  void AddNewWords(string text);
  void AddNewCount(int num);
  void Union(string text, int num);
  bool checkitem(string item, int num);
  bool checknewitem(string item, int num);
  void SubtractWords(string text, int num);
  void DifferenceWords(string text, int num);
  void IntersectWords();
  void ResetWord();
  void PrintWords();
  void SearchWord(string text);
  void Insert(string text, int num);
  void DeleteWord(string word3);
  void Reduce(string text, int num);
  void MaxWords(int num);

};
