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

void BracketChecker::checkArray(char* argv) { 
    int errorLine = 0;  // Line number tracker
    ifstream file(argv);

    // Check if file exists
    if (!file.good()) {
        throw invalid_argument("file could not be opened");
    }

    string line;

    // Iterate through each line in the file
    while (getline(file,line)){
        errorLine++; 

        // Check each character in the line
        for (char potentialBracket : line){
            
            // If it's an opening bracket, push onto the stack
            if ((potentialBracket=='{')||(potentialBracket=='[')||(potentialBracket=='(')){
                bracketStack.push(potentialBracket);
            } 
            // If it's a closing bracket, check for its match
            else if ((potentialBracket=='}')||(potentialBracket==']')||(potentialBracket==')')) {
                // If stack is empty, there's no opening bracket to match this
                if (bracketStack.isEmpty() == true){
                    cout << "Bracket Mismatch Detected for " << potentialBracket << " in line " << errorLine << "." << endl;
    return;
                    
                }

                char topBracket = bracketStack.peek();

                // Check if top of stack is a matching opening bracket
                if ((potentialBracket == '}' && topBracket == '{') ||
                    (potentialBracket == ']' && topBracket == '[') ||
                    (potentialBracket == ')' && topBracket == '(')) {
                    bracketStack.pop();  // If yes, pop it off the stack
                }
                else {
                    cout << "Bracket Mismatch Detected for " << potentialBracket << " in line " << errorLine << "." << endl;
                    return;
                }
            }
        }
    }

    file.close();
 
    // Check for unmatched opening brackets left in the stack
    if (!bracketStack.isEmpty()){
        cout << "Bracket Mismatch Detected for " << bracketStack.peek() << " in line " << errorLine << "." << endl;
        return;
    }
    else{
        cout << "Ok, Brackets Match!" << endl;
    }
} 

void BracketChecker::checkList(char* argv) { 
    int errorLine = 0;
    ifstream file(argv);

    // Check if file exists
    if (!file.good()) {
        throw invalid_argument("file could not be opened");
    }

    string line;

    // Iterate through each line in the file
    while (getline(file,line)){
        errorLine++;
        
        // Check each character in the line
        for (char potentialBracket : line){
            
            // If it's an opening bracket, push onto the stack
            if ((potentialBracket=='{')||(potentialBracket=='[')||(potentialBracket=='(')){
                bracketStackList.push(potentialBracket);
            } 
            // If it's a closing bracket, check for its match
            else if ((potentialBracket=='}')||(potentialBracket==']')||(potentialBracket==')')) {

                // If stack is empty, there's no opening bracket to match this
                if (bracketStackList.isEmpty() == true){
                   cout << "Bracket Mismatch Detected for " << potentialBracket << " in line " << errorLine << "." << endl;
                    return;
                }

                char topBracket = bracketStackList.peek();

                // Check if top of stack is a matching opening bracket
                if ((potentialBracket == '}' && topBracket == '{') ||
                    (potentialBracket == ']' && topBracket == '[') ||
                    (potentialBracket == ')' && topBracket == '(')) {
                    bracketStackList.pop();  // If yes, pop it off the stack
                }
                else {
                    cout << "Bracket Mismatch Detected for " << potentialBracket << " in line " << errorLine << "." << endl;
                    return;
                }
            }
        }
    }
 file.close();
    // Check for unmatched opening brackets left in the stack
    if (!bracketStackList.isEmpty()){
        cout << "Bracket Mismatch Detected for " << bracketStackList.peek()  << " in line " << errorLine << "." << endl;
        return;
    }
    else{
        cout << "Ok, Brackets Match!" << endl;
    }
}