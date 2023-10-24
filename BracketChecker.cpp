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

    //file is read in through passed arg
    ifstream file("/users7/cse/rmukherji/assignment-3-do-my-brackets-match-riamuk101/test_data/DSVector_good.h");
    //std::ifstream file("/users7/cse/rmukherji/assignment-3-do-my-brackets-match-riamuk101/test_data/fake.txt");
    if (!file.good())
    {
           throw std::invalid_argument("file could not be opened");
    }

    //once file is open declare DSStack_Array
 
    std :: string line; 

while (getline(file,line)){
    
        for (char potentialBracket : line){
            if ((potentialBracket=='{')||(potentialBracket=='[')||(potentialBracket=='(')){
                bracketStack.push(potentialBracket);
            
            }//end if 
           else if ((potentialBracket=='}')||(potentialBracket==']')||(potentialBracket==')')) {
          if (bracketStack.isEmpty() == true){
              cout << "brackets don't match ";
          }
          char topBracket = bracketStack.peek();
          if ((potentialBracket == '}' && topBracket == '{') ||
           (potentialBracket == ']' && topBracket == '[') ||
            (potentialBracket == ')' && topBracket == '(')) {
            //cout << "match ";
            bracketStack.pop();
        }
        else{

            cout << "brackets don't match ";
            return;
        }
       
        }//end for 


        }
}// end while loop 


if (bracketStack.isEmpty()==false){
    cout << "brackets don't match ";
}
else{
    cout << "brackets match ";
} 

}//end checkArray

// void BracketChecker::checkList() { 

//     //file is read in through passed arg
//     ifstream file("/users7/cse/rmukherji/assignment-3-do-my-brackets-match-riamuk101/test_data/DSVector_good.h");
//     //std::ifstream file("/users7/cse/rmukherji/assignment-3-do-my-brackets-match-riamuk101/test_data/fake.txt");
//     if (!file.good())
//     {
//            throw std::invalid_argument("file could not be opened");
//     }

//     //once file is open declare DSStack_Array
 
//     std :: string line; 

// while (getline(file,line)){
    
//         for (char potentialBracket : line){
//             if ((potentialBracket=='{')||(potentialBracket=='[')||(potentialBracket=='(')){
//                 bracketStackList.push(potentialBracket);
            
//             }//end if 
//            else if ((potentialBracket=='}')||(potentialBracket==']')||(potentialBracket==')')) {
//           if (bracketStackList.isEmpty() == true){
//               cout << "brackets don't match ";
//           }
//           char topBracket = bracketStackList.peek();
//           if ((potentialBracket == '}' && topBracket == '{') ||
//            (potentialBracket == ']' && topBracket == '[') ||
//             (potentialBracket == ')' && topBracket == '(')) {
//             //cout << "match ";
//             bracketStackList.pop();
//         }
//         else{

//             cout << "brackets don't match ";
//             return;
//         }
       
//         }//end for 


//         }
// }// end while loop 


// if (bracketStackList.isEmpty()==false){
//     cout << "brackets don't match ";
// }
// else{
//     cout << "brackets match ";
// } 

// }//end checkArray

