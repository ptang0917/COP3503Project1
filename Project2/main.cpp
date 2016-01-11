#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include "project2.h"
using namespace std;



int main(int argc, char ** argv) {
    Set myset;  //myset is declared to get functions from Set structure
    ifstream input1; //gets the input from the txt file
   
    ofstream output1; //gets the output from the current set to save it to the text file
    string filename; //name for the filename being added either the current set array or the new array

    string outputfilename; //name for the out put file name that is being 'saved ' to a new text file.
    string content;  //contents from the text files
    string s;
    int n;
    int maxstuff = 0;
    int wordcount = 0;
  
    bool VERBOSE = false; //Setting whether VERBOSE mode is on or off
    bool NORMAL = true; //Setting whether NORMAL mode is on or off. for now it is on
  int i = 20;
      //Displaying the options for users to choose and show the users what each options do
      std::cout << "0. exit" << std::endl;
      std::cout << "1. input file <filename>: open and read a list from a file to the current list" << std::endl;
      std::cout << "2. union file <filename>: open and union a set from a file with the current set" << std::endl;
      std::cout << "3. subtract file <filename>: open and subtract set from a file from the current set" << std::endl;
      std::cout << "4. difference file <filename>: open and find the difference between a set from a file and the current set" << std::endl;   
      std::cout << "5. intersect file <filename>: open and find the intersection between a set from a file and the current set" << std::endl;
      std::cout << "6. reset current set to the empty set" << std::endl;
      std::cout << "7. output file <filename>: open and write the current set to a file" << std::endl;
      std::cout << "8. print current set to the console" << std::endl;
      std::cout << "9. find <item name>: test if <item name> is in the current set" << std::endl;
      std::cout << "10. insert <item name> <count>: add <item name> to the current multiset with number <count>"<< std::endl; 
      std::cout << "if <item name> is not in the current multiset, or increase <item name>'s number by <count>" << std::endl;
      std::cout << "11. delete <item name>: remove <item name> from the current set if it is in it" << std::endl;
      std::cout << "12. reduce <item name> <count>: reduce the number of <item name> by <count>" << std::endl;
      std::cout << "13. verbose output" << std::endl;
      std::cout << "14. normal output" << std::endl;
      std::cout << "15. silent output" << std::endl;
      std::cout << "16. help" << std::endl; 
      std::cout << "17. Find Max" << std::endl;
  
  //A loop that lets people can choose what ever the options that he or she wishes to implement as long they don't type in 0.
  while(i != 0) {

     if(NORMAL) { //Users will be seeing this ">" sign when NORMAL mode is on. 
        cout << "> " ;
       }
       else if(VERBOSE) {
        //Users will be seeing the menu when setting VERBOSE mode to on.
        std::cout << "0. exit" << std::endl;
        std::cout << "1. input file <filename>: " << std::endl;
        std::cout << "2. union file <filename>: " << std::endl;
        std::cout << "3. subtract file <filename>: " << std::endl;
        std::cout << "4. difference file <filename>: " << std::endl;   
        std::cout << "5. intersect file <filename>: " << std::endl;
        std::cout << "6. reset " << std::endl;
        std::cout << "7. output file <filename>:" << std::endl;
        std::cout << "8. print current set " << std::endl;
        std::cout << "9. find <item name>: " << std::endl;
        std::cout << "10. insert <item name>: " << std::endl;
        std::cout << "11. delete <item name>: " << std::endl;
        std::cout << "12. reduce <iten name>" << std::endl;
        std::cout << "13. verbose output" << std::endl;
        std::cout << "14. normal output" << std::endl;
        std::cout << "15. silent output" << std::endl;
        std::cout << "16. help" << std::endl;
        std::cout << "17. Find Max" << std::endl;
        cout << "> " ;
       } 
        std::cin >> i ;
        if(i == 0) {
             break;
             //Exits the menu when the users enters 0
        }
        else if(i == 1){
            
         if(VERBOSE || NORMAL) {
          //if VERBOSE mode is on or the NORMAL mode is on, then the users can see this code stating the user to type the file
          //that users wish to type the file
          std::cout << "Type the file you want to input" << std::endl;
          }
          std::cin >> filename;
          
          
        
            input1.open(filename.c_str());
            
             if(input1.fail()) {
               //Gives like an error should the file fail to open.
               cout << "File " << filename << " does not exist" << endl;
               return -1;
            }
            while(!input1.eof()) {
               
               while(getline(input1, content)) {
                 istringstream record(content);
                 record >> s;
                 record >> n;
                 if(record.fail()) {
                cerr << "line malformed: " << content << endl;
                }
                 myset.AddSetWords(s);
                 myset.AddCount(n);

	
               }
              content.clear();
            }
            if(VERBOSE || NORMAL) {
              std::cout << "New set loaded" << std::endl;
            input1.close();
          }  
        }
                  
 
        else if(i == 2){
          
     
           if(VERBOSE || NORMAL) {
             std::cout << "Type the file you want to union with the current set" << std::endl;
            } 
           std::cin >> filename;
           input1.open(filename.c_str());
               
           if(input1.fail()) {
             std::cout << "File " << filename << " cannot be opened" << endl;
             return -1;
           }
          
            while(!input1.eof()) {
               
             while(getline(input1, content)) {
                 istringstream record(content);
                 record >> s;
                 record >> n;
                 if(record.fail()) {
                 cerr << "line malformed: " << content << endl;
               }
                
				          myset.Union(s,n);
               }

            content.clear();
            
           }
           
           if(VERBOSE || NORMAL) {
             
            std::cout << "Union loaded" << std::endl; 
            input1.close();
          }
 
        }
        else if(i == 3){
            if(VERBOSE || NORMAL) {
               std::cout << "Type the file you want to subtract" << std::endl;
             }  
               std::cin >> filename;
               input1.open(filename.c_str());
            
            
            if(input1.fail()) {
               std::cout << "File " << filename << " cannot be opened or does not exist." << std::endl;
               return -1;
            }
            while(!input1.eof()) {
               while(getline(input1,content)) {
               istringstream record(content);
               record >> s;
               record >> n;
               if(record.fail()) {
                cerr << "line malformed: " << content << endl;
                return -1;
              }

               myset.SubtractWords(s,n);
              }                
              content.clear();
            }
            if (VERBOSE || NORMAL) {
               cout << "Subtraction completed" << endl;
               input1.close();
            }
            
        }
        else if(i == 4){
          if(VERBOSE || NORMAL) {
           cout << "Type file do you want to find the difference" << endl;
          }
          cin >> filename;
          input1.open(filename.c_str());
          if(input1.fail()) {
            cout << "File " << filename << " cannot be opened or does not exist" << endl;
           
          }
          while(!input1.eof()) {
            while(getline(input1,content)){
              istringstream record(content);
              record >> s;
              record >> n;
              myset.DifferenceWords(s,n);
              if(record.fail()) {
                cerr << "line malformed: " << content << endl;
              }
            }
            content.clear(); 
          }
          if(VERBOSE || NORMAL) {
          
           cout << "Difference Completed" << std::endl;
           input1.close();
          }

        }
        else if(i == 5) {
        if(VERBOSE || NORMAL) {
         std::cout << "Which file do you want to intersect ?" << std::endl;
        } 
         std::cin >> filename;
         
           input1.open(filename.c_str());
          if(input1.fail()) {
            std::cout << "Wrong type for " << filename << " please try again" << endl;
            return -1;
          }  
          while(!input1.eof()) {
            while(getline(input1, content)) {
              istringstream record(content);
              record >> s;
              record >> n;
              if(record.fail()) {
                cerr << "line malformed: " << content << endl;
              }
             myset.AddNewWords(s);
             myset.AddNewCount(n);
            }
           
            
           
            content.clear();
          }
          myset.IntersectWords();
          if(VERBOSE || NORMAL) {
           
           std::cout << "Intersect completed " << std::endl;
           input1.close();
         }
              
        }
        else if(i == 6) {
        if(VERBOSE || NORMAL) {
            std::cout << "Reset completed" << std::endl;
            
          }
          myset.ResetWord();
          
        }
        
        else if(i == 7) {
           if(VERBOSE || NORMAL) {
         
            
            input1.open(filename.c_str());
            
             
            cout << "Output file name: " << flush;
            cin >> outputfilename;
            output1.open(outputfilename.c_str());
            if(output1.fail()) {
            cout <<"File " << outputfilename << " is an invalid name" << endl;
            return -1;
        }
        
        
            
 
        
             while(!input1.eof()) {
               input1 >> content;
               output1 << content << endl;
              
              
               
            }   
           
            }
             cout << "Saved to " << outputfilename << endl;
             input1.close();
              content.clear();
            

        } 
        else if(i == 8){
          if(VERBOSE || NORMAL) {
            cout << "Current set :" << endl;
          }
          myset.PrintWords();
          


        }
        else if(i == 9){
		  string search1;
          if(VERBOSE || NORMAL) {
          std::cout << "Enter the word that you want to search" << std::endl;
          }
          
          cin >> search1;
        
         
          myset.SearchWord(search1);
          
          
        }
        else if(i == 10){
          
          string addword;
          if(VERBOSE || NORMAL) {
          std::cout << "Enter the word that you want to add" << std::endl;
          }
          std::cin >> addword >> wordcount;
		  
          myset.Insert(addword, wordcount);
          
          
          
          
        }
        
        else if(i == 11){
          string removeword;
          
          if(VERBOSE || NORMAL) {
          std::cout << "Enter the word that you want to delete" << std::endl;
          }
          std::cin >> removeword;
          myset.DeleteWord(removeword);
          
          if(VERBOSE || NORMAL) {
            std::cout << "delete completed" << std::endl;
          }
        }
        
        else if(i == 12){
          string reduceword;
          if(VERBOSE || NORMAL) {
          std::cout << "Enter the word that you want to reduce" << std::endl;
          }
          std::cin >> reduceword >> wordcount;
          
          myset.Reduce(reduceword, wordcount);
          
          
          
         
        }
        
        else if(i == 13) {
           VERBOSE = true;
           NORMAL = false;
        }
        
        else if(i == 14){
          VERBOSE = false;
          NORMAL = true;
          
        }
        
        else if(i == 15){
          VERBOSE = false;
          NORMAL = false;
        }
        
        else if(i == 16){
        std::cout << "0. exit" << std::endl;
        std::cout << "1. input file <filename>: open and read a list from a file to the current list" << std::endl;
        std::cout << "2. union file <filename>: open and union a set from a file with the current set" << std::endl;
        std::cout << "3. subtract file <filename>: open and subtract set from a file from the current set" << std::endl;
        std::cout << "4. difference file <filename>: open and find the difference between a set from a file and the current set" << std::endl;   
        std::cout << "5. intersect file <filename>: open and find the intersection between a set from a file and the current set" << std::endl;
        std::cout << "6. reset current set to the empty set" << std::endl;
        std::cout << "7. output file <filename>: open and write the current set to a file" << std::endl;
        std::cout << "8. print current set to the console" << std::endl;
        std::cout << "9. find <item name>: test if <item name> is in the current set" << std::endl;
        std::cout << "10. insert <item name>: add <item name> to the current set if it is not already in it" << std::endl;
        std::cout << "11. delete <item name>: remove <item name> from the current set if it is in it" << std::endl;
        std::cout << "12. reduce <item name> <count>: reduce the number of <item name> in the current multiset by <count> if it is in it " << std::endl;
        std::cout << "13. verbose output" << std::endl;
        std::cout << "14. normal output" << std::endl;
        std::cout << "15. silent output" << std::endl;
        std::cout << "16. help" << std::endl;
        std::cout << "17. Find Max" << std::endl;

        } 

        else if(i == 17) {
          std::cout << "Set the Maximum amount of word for the current multiset" << std::endl;
          std::cin >> maxstuff; 
          std::cout << "The Maximum amount of word in the current multiset is now " << maxstuff << std::endl;
          myset.MaxWords(maxstuff);
        }
        else {
        std::cout << "COMMAND INVALID PLEASE TRY AGAIN" << std::endl;
        
        } 
       
        
     
  } 
    return 0; 
 }  
  
