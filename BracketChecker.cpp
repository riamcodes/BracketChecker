
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

// This function checks for matching brackets in a given file using an array-based stack.
void BracketChecker::checkArray(char* argv) { 
    int errorLine = 0;  // Keeps track of the current line number
    ifstream file(argv); // Open the file with the provided filename

    // Check if the file is opened successfully
    if (!file.good()) {
        throw invalid_argument("file could not be opened");
    }

    string line;
    // Process each line in the file
    while (getline(file,line)){
        errorLine++; 
        // Examine each character in the current line
        for (char potentialBracket : line) {
            // If the character is an opening bracket, push it onto the stack
            if ((potentialBracket=='{')||(potentialBracket=='[')||(potentialBracket=='(')) {
                bracketStack.push(potentialBracket);
            } 
            // If the character is a closing bracket, process it
            else if ((potentialBracket=='}')||(potentialBracket==']')||(potentialBracket==')')) {
                // If the stack is empty, a mismatch is detected
                if (bracketStack.isEmpty()) {
                    cout << "Bracket Mismatch Detected for " << potentialBracket << " in line " << errorLine << "." << endl;
                    return;
                }
                char topBracket = bracketStack.peek(); // Check the top of the stack

                // Check if the top of the stack has the matching opening bracket for the current closing bracket
                if ((potentialBracket == '}' && topBracket == '{') ||
                    (potentialBracket == ']' && topBracket == '[') ||
                    (potentialBracket == ')' && topBracket == '(')) {
                    bracketStack.pop(); // If it's a match, pop the top bracket off the stack
                }
                else {
                    cout << "Bracket Mismatch Detected for " << potentialBracket << " in line " << errorLine << "." << endl;
                    return;
                }
            }
        }
    }
 
    // After processing the entire file, check if there's any unmatched opening bracket left in the stack
    if (!bracketStack.isEmpty()) {
        cout << "Bracket Mismatch Detected for " 
             << (bracketStack.peek() == '{' ? '}' : (bracketStack.peek() == '[' ? ']' : ')')) 
             << " in line " << errorLine << "." << endl;
    }
    else {
        cout << "Ok, Brackets Match!" << endl;
    }
}

// This function checks for matching brackets in a given file using a linked-list based stack.
void BracketChecker::checkList(char* argv) { 
    int errorLine = 0; // Keeps track of the current line number
    ifstream file(argv); // Open the file with the provided filename

    // Check if the file is opened successfully
    if (!file.good()) {
        throw invalid_argument("file could not be opened");
    }

    string line;

    // Process each line in the file
    while (getline(file,line)){
        errorLine++;
        
        // Examine each character in the current line
        for (char potentialBracket : line){
            
            // If the character is an opening bracket, push it onto the stack
            if ((potentialBracket=='{')||(potentialBracket=='[')||(potentialBracket=='(')){
                bracketStackList.push(potentialBracket);
            } 
            // If the character is a closing bracket, process it
            else if ((potentialBracket=='}')||(potentialBracket==']')||(potentialBracket==')')) {

                // If the stack is empty, a mismatch is detected
                if (bracketStackList.isEmpty() == true){
                    cout << "Bracket Mismatch Detected for " << potentialBracket << " in line " << errorLine << "." << endl;
                    return;
                }

                char topBracket = bracketStackList.peek(); // Check the top of the stack

                // Check if the top of the stack has the matching opening bracket for the current closing bracket
                if ((potentialBracket == '}' && topBracket == '{') ||
                    (potentialBracket == ']' && topBracket == '[') ||
                    (potentialBracket == ')' && topBracket == '(')) {
                    bracketStackList.pop(); // If it's a match, pop the top bracket off the stack
                }
                else {
                    cout << "Bracket Mismatch Detected for " << potentialBracket << " in line " << errorLine << "." << endl;
                    return;
                }
            }
        }
    }
 
    // After processing the entire file, check if there's any unmatched opening bracket left in the stack
    if (!bracketStackList.isEmpty()){
        cout << "Bracket Mismatch Detected for " << (bracketStackList.peek() == '{' ? '}' : (bracketStackList.peek() == '[' ? ']' : ')')) << " in line " << errorLine << "." << endl;
        return;
    }
    else{
        cout << "Ok, Brackets Match!" << endl;
    }
}
