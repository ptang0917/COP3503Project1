#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//This is a constant global variable representing the limit of words can be put in the current set
const int maxwords = 100;

struct Set{
  
  //global variables of the array and number of words; 
  string arraywords[maxwords];
  string newarray[maxwords];
  
  
  int numwords;
  
  int numlength;
  
  Set() {
    
    numwords = 0;
    
    numlength = 0;
    
  }
  //Moving the contents from the current set text file to an array
  //This is function for option 1
  void AddSetWords(string text) {
    arraywords[numwords] = text;
    
    ++numwords;
    
  }
  
  //Adding contents from a new set text file to a new array
  void AddNewWords(string text) {
     newarray[numlength] = text;
     ++numlength;
  
  }
  
  
  //This is the function for option 2   
  void UnionWord() {
    //This function requires a nested loop, the first loop goes through the array the first time 
    //The second loop goes through the array second time and if the element is same as the element that the first loop checked
    //It removes the duplicate.
    
    for(int i = 0; i < numwords; ++i) {
         for(int j = i+1; j < numwords; j++) {
            if(arraywords[i] == arraywords[j]){ 
                
               arraywords[j] = arraywords[j+1];
			   arraywords[j] = "";
              
               
            }
         }
        
         
    }
    
    
  }   
  
  //This function is use to check if that paticular item is in the current array
  bool checkitem(string item) {
    bool check = false;
    for(int i = 0; i < numwords; i++) {
      if(item == arraywords[i]) {
         check = true;
         break;
      }
    }
    return check;
  }
  
    //This function is use to check if that paticular item is in the new array

  bool checknewitem(string item) {
     bool check = false;
     for(int i = 0; i < numlength; i++){
       if(item == newarray[i]) {
         check = true;
         break;
       }
     }
     return check;
  }
  
  //This function is used to implement option 3 where it subtracts the current set from the new set of array that's implemented
  //from the new inputted file. 
  void SubtractWords() {
  	  int index=0;
      for(int i = 0; i < numwords; ++i) {
         
           if(!checknewitem(arraywords[i])) {
               
              arraywords[index] = arraywords[i]; 
              index++;  
           }
           
          
      }
      numwords = index;
      numlength = 0;
      
  }
  
  void DifferenceWords() {
     int index = 0;
     string temparray[100];
      for(int i = 0; i < numwords; ++i) {
        if(!checknewitem(arraywords[i])) {
               
              temparray[index] = arraywords[i]; 
              index++;  
           }
      }
      for(int i = 0; i < numlength; i++){
          if(!checkitem(newarray[i])) {
               
              temparray[index] = newarray[i]; 
              index++;  
           }
         }
        for(int i = 0; i < index; i++) {
            arraywords[i] = temparray[i];
        } 
        numwords = index;
        numlength = 0;
      }
      
  
  
  void IntersectWords() {
      int index = 0;
  	
  	
      for(int i = 0; i < numwords; i++) {
     
         if(checknewitem(arraywords[i])){
         	
            arraywords[index] = arraywords[i];
            index++;
            
         }
         
      }
      
      numwords = index;
      numlength = 0;
  }
  
  
  
  //This function resets the current set by replacing all the elements to 'empty spaces'
  void ResetWord() {
    
  
    for(int i = 0; i < numwords; ++i){
      
      arraywords[i] = arraywords[i+1];
      arraywords[i] = "";
      numwords--;
     }
     

  }
  
  
  //This function is the function for Option 8: prints the current set of the array 
  void PrintWords() {
      
      
     for(int i = 0; i < numwords; ++i) { 
       //This if statement is make sure there isn't any "empty spaces" or "duplicates" when removing arrays 
       if(arraywords[i].length() > 0) {
         std::cout << arraywords[i]  << std::endl; 
        } 
     } 
  }
  
  //This function is used for option 9 where it searches the current array for the given word
  void SearchWord(string text) {
     int found = 0;
     for(int i = 0; i < numwords; i++){
        if(arraywords[i] == text) {
           found = 1;
           break;
          }
        }
      if(found) {
       std::cout << "Item " << text << " found " << std::endl;
      }
      else {
       std::cout << "Item " << text << "  not found " << std::endl;
      }
    } 
 
 //goes through the array and delete the word in the current set
 //This is function is used for option 11 
 void DeleteWord(string word3) {

    int i; 
    for( i = 0; i < numwords; i++) {
       if(arraywords[i] == word3) {
      
          arraywords[i] = arraywords[i+1];
          arraywords[i] = "";
        }
        
     }
    
            
  }  
};

int main(int argc, char ** argv) {
    Set myset;  //myset is declared to get functions from Set structure
    ifstream input1; //gets the input from the txt file
   
    ofstream output1; //gets the output from the current set to save it to the text file
    string filename; //name for the filename being added either the current set array or the new array

    string outputfilename; //name for the out put file name that is being 'saved ' to a new text file.
    string content;  //contents from the text files
  
  
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
      std::cout << "10. insert <item name>: add <item name> to the current set if it is not already in it" << std::endl;
      std::cout << "11. delete <item name>: remove <item name> from the current set if it is in it" << std::endl;
      std::cout << "12. verbose output" << std::endl;
      std::cout << "13. normal output" << std::endl;
      std::cout << "14. silent output" << std::endl;
      std::cout << "15. help" << std::endl; 
  
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
        std::cout << "12. verbose output" << std::endl;
        std::cout << "13. normal output" << std::endl;
        std::cout << "14. silent output" << std::endl;
        std::cout << "15. help" << std::endl;
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
               input1 >> content;
               
               myset.AddSetWords(content);
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
            input1 >> content;
            myset.AddSetWords(content);
            myset.UnionWord();
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
               std::cout << "File " << filename << "cannot be opened" << std::endl;
               return -1;
            }
            while(!input1.eof()) {
               input1 >> content;
               myset.AddNewWords(content);
               content.clear();
               myset.SubtractWords();
               
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
            cout << "File " << filename << " cannot be opened" << endl;
            return -1;
          }
          while(!input1.eof()) {
             input1 >> content;
             myset.AddNewWords(content);
             myset.DifferenceWords();
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
            input1 >> content;
            myset.AddNewWords(content);
            
           
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
//               myset.AddSetWords(content);
              
               
            }   
           
            }
             cout << "Saved to " << outputfilename << endl;
             input1.close();
              content.clear();
            

        } 
        else if(i == 8){
          myset.PrintWords();
          


        }
        else if(i == 9){
          string search1; 
          if(VERBOSE || NORMAL) {
          std::cout << "Enter the word that you want to search" << std::endl;
          }
          std::cin >> search1;
          
          myset.SearchWord(search1);
        }
        else if(i == 10){
         
          string addword;
          if(VERBOSE || NORMAL) {
          std::cout << "Enter the word that you want to add" << std::endl;
          }
          std::cin >> addword;
          myset.AddSetWords(addword);
          if(VERBOSE || NORMAL) {
          std::cout << "Item " << addword << " inserted" << std::endl;
          }
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
           VERBOSE = true;
           NORMAL = false;
          }
        
        else if(i == 13){
          VERBOSE = false;
          NORMAL = true;
          
        }
        
        else if(i == 14){
          VERBOSE = false;
          NORMAL = false;
        }
        
        else if(i == 15){
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
        std::cout << "12. verbose output" << std::endl;
        std::cout << "13. normal output" << std::endl;
        std::cout << "14. silent output" << std::endl;
        std::cout << "15. help" << std::endl;

        } 
        else {
        std::cout << "COMMAND INVALID PLEASE TRY AGAIN" << std::endl;
        return -1;
        } 
       
        
  	 
  }	
    return 0;	
 } 	
	
