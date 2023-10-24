#include <chrono>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "BracketChecker.h"
#include "DSStack.h"
#include "DSStack_LinkedList.h"
#include "DSList.h"
#include <map>
#include <iomanip>

using namespace std;


void BracketChecker::checkArray() { 
int errorLine  = 0;
    //file is read in through passed arg
    ifstream file("/users7/cse/rmukherji/assignment-3-do-my-brackets-match-riamuk101/test_data/DSVector_bad.h");
    //std::ifstream file("/users7/cse/rmukherji/assignment-3-do-my-brackets-match-riamuk101/test_data/fake.txt");
    if (!file.good())
    {
           throw std::invalid_argument("file could not be opened");
    }

    //once file is open declare DSStack_Array
 
    std :: string line; 

while (getline(file,line)){
    errorLine++; 
        for (char potentialBracket : line){
            if ((potentialBracket=='{')||(potentialBracket=='[')||(potentialBracket=='(')){
                bracketStack.push(potentialBracket);
            
            }//end if 
           else if ((potentialBracket=='}')||(potentialBracket==']')||(potentialBracket==')')) {
          if (bracketStack.isEmpty() == true){
              cout << "brackets don't match. Error on line " << errorLine << endl;
              return;
          }
          char topBracket = bracketStack.peek();
          if ((potentialBracket == '}' && topBracket == '{') ||
           (potentialBracket == ']' && topBracket == '[') ||
            (potentialBracket == ')' && topBracket == '(')) {
            //cout << "match ";
            bracketStack.pop();
        }
        else{

            cout << "brackets don't match. Error on line " << errorLine << endl;
            return;
        }
       
        }//end for 


        }
}// end while loop 


if (bracketStack.isEmpty()==false){
cout << "brackets don't match. Error on line: " << errorLine << endl;
return;
}
else{
    cout << "brackets match " << endl;
} 

}//end checkArray

void BracketChecker::checkList() { 
int errorLine  = 0;
    //file is read in through passed arg
     ifstream file("/users7/cse/rmukherji/assignment-3-do-my-brackets-match-riamuk101/test_data/DSVector_bad.h");
    //std::ifstream file("/users7/cse/rmukherji/assignment-3-do-my-brackets-match-riamuk101/test_data/fake.txt");
    if (!file.good())
     {
            throw std::invalid_argument("file could not be opened");
     }

    //once file is open declare DSStack_Array
 
    std :: string line; 

while (getline(file,line)){
    errorLine++;
    
        for (char potentialBracket : line){
            if ((potentialBracket=='{')||(potentialBracket=='[')||(potentialBracket=='(')){
                bracketStackList.push(potentialBracket);
            
            }//end if 
           else if ((potentialBracket=='}')||(potentialBracket==']')||(potentialBracket==')')) {
          if (bracketStackList.isEmpty() == true){
              cout << "brackets don't match. Error on line: " << errorLine << endl;
              return;
          }
          char topBracket = bracketStackList.peek();
          if ((potentialBracket == '}' && topBracket == '{') ||
           (potentialBracket == ']' && topBracket == '[') ||
            (potentialBracket == ')' && topBracket == '(')) {
            //cout << "match ";
            bracketStackList.pop();
        }
        else{

           cout << "brackets don't match. Error on line: " << errorLine << endl;
            return;
        }
       
        }//end for 


        }
}// end while loop 


if (bracketStackList.isEmpty()==false){
    cout << "brackets don't match. Error on line: " << errorLine << endl;
    return;
}
else{
    cout << "brackets match ";
} 

}//end checkArray

