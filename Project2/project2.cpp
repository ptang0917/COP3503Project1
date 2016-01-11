#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include "project2.h"
using namespace std;

Set::Set() {
    maxnum = 100;
    numwords = 0;
    numcount = 0;
    numlength = 0;
    countlength = 0;
}
 
void Set::AddSetWords(string text) {
    arraywords[numwords] = text;
    ++numwords;
    if(numwords > maxnum) {
      std::cout << "ERROR EXCEEDS CAPACITY" << std::endl;
    }
}
  
void Set::AddCount(int num) {
    arraycount[numcount] = num;
    ++numcount;
    if(numcount > maxnum) {
      std::cout << "ERROR EXCEEDS CAPACITY" << std::endl;
    }
}

void Set::AddNewWords(string text) {
     newarray[numlength] = text;
     ++numlength;
}

void Set::AddNewCount(int num) {
  newcountarray[countlength] = num;
  ++countlength;
}
  
void Set::Union(string text, int num) {
    
    int i;
    for( i = 0; i < numwords; ++i) {
         
        
        if(arraywords[i] == text) {
           arraycount[i] += num;
           
           break;
           
        }
    }
     if(arraywords[i] != text) {
           AddSetWords(text);
           AddCount(num);
           
    }
  }   
  
bool Set::checkitem(string item, int num) {
    bool check = false;
    for(int i = 0; i < numwords; i++) {
      if(item == arraywords[i] && num == arraycount[i]) {
         check = true;
         break;
      }
    }
    return check;
}  
 
bool Set::checknewitem(string item, int num) {
     bool check = false;
     for(int i = 0; i < numlength; i++){
       if(item == newarray[i] && num == arraycount[i]) {
         check = true;
         break;
       }
     }
     return check;
}

void Set::SubtractWords(string text, int num) {
     for(int i = 0; i < numwords; ++i) {
         if(arraywords[i] == text){ 
               arraycount[i] -= num;
               
           }
         if(arraycount[i] <= 0) {
             arraywords[i] = arraywords[i+1];
               arraywords[i] = "";
              
          }
          }
 
} 

void Set::DifferenceWords(string text, int num) {

        int i;
    for( i = 0; i < numwords; i++) {
       if(arraywords[i] == text ) {
          arraycount[i] = abs(num - arraycount[i]);  //Making the value of 'arraycount[i]' an absolute value to make sure that there isn't a negative value.
          break;
       }
       if(arraycount[i] == 0) {
             arraywords[i] = arraywords[i+1];
               arraywords[i] = "";
              
          }
    }
    if(arraywords[i] != text) {
       AddSetWords(text);
       AddCount(num);
    }
      
}

void Set::IntersectWords() {
      int index = 0;
      int count = 0;
    
      for(int i = 0; i < numwords; i++) {
     
         if(checknewitem(arraywords[i],arraycount[i])){
          
            arraywords[index] = arraywords[i];
            arraycount[count] = arraycount[i];
            index++;
            count++;
         }
         
      }
      
      numwords = index;
      numlength = 0;
      numcount = count;
      countlength = 0;
}

void Set::ResetWord() {
    
  
    for(int i = 0; i < numwords; ++i){
      
      arraywords[i] = arraywords[i+1];
      arraywords[i] = "";
      
     }
}

void Set::PrintWords() {
      
      
     for(int i = 0; i < numwords; ++i) { 
       //This if statement is make sure there isn't any "empty spaces" or "duplicates" when removing arrays 
       if(arraywords[i].length() > 0) {
         std::cout << arraywords[i]  << " " << arraycount[i] << std::endl; 
        } 
     } 
}

void Set::SearchWord(string text) {
     int found = 0;
     int i = 0;
     for( i = 0; i < numwords; i++){
       
        if(arraywords[i] == text) {
           found = 1;
           break;
          }
        }
      if(found) {
       std::cout << "Item " << text << " found " << " with a count of " << arraycount[i] << std::endl;
      }
      else {
       std::cout << "Item " << text << "  not found " << std::endl;
      }
} 

 
void Set::Insert(string text, int num) {
     int i =0;
     int j = 0;
     int dupe = 0;
    
      for( i = 0; i < numwords; ++i) {
       
        if(arraywords[i] == text) {
           arraycount[i] += num;
           dupe = 1;
           
           break;
           
        }
         
         
      }
      if(!dupe) {
         AddSetWords(text);
         AddCount(num);
          
      }
      cout << text << " inserted with " << arraycount[i] << " count" << endl;
      //Should the user insert a new word and a new count, then that word will be added to the current set with the existing contents.
     
}

void Set::DeleteWord(string word3) {

    int i; 
    for( i = 0; i < numwords; i++) {
       if(arraywords[i] == word3) {
      
          arraywords[i] = arraywords[i+1];
          arraywords[i] = "";
        }
        
     }
}

void Set::Reduce(string text, int num) {
    int i =0;
     int j = 0;
     int deleted = 0;
      for( i = 0; i < numwords; ++i) {
         
            if(arraywords[i] == text){ 
               arraycount[i] -= num;
               deleted = 0;
               break;
              
           }
          
         
    }
         if(arraycount[i] <= 0) {
             arraywords[i] = arraywords[i+1];
               arraywords[i] = "";
               deleted = 1;
               
          }

        if(deleted) {
          cout << text << " is deleted" << endl;
        }  
        if(!deleted) {
          cout << text << " count reduced to   " << num << " count" <<  endl;
        }
 }  
 
 void Set::MaxWords(int num) {
    maxnum = num;
}
