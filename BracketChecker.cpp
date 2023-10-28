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

// Function to check matching brackets using arrays
void BracketChecker::checkArray(char* argv) { 
    int errorLine = 0;  // Track the current line number
    DSStack<int> lineStack; // Stack to remember line numbers where brackets were pushed
   
    ifstream file(argv); // Open the input file

    // Check if the file can be opened correctly
    if (!file.good()) {
        throw invalid_argument("file could not be opened");
    }

    string line;
    // Loop through each line of the file
    while (getline(file,line)){
        errorLine++; 



        // Check each character in the line for potential brackets
        for (char potentialBracket : line){
            
            // Push opening brackets onto the stack
            if ((potentialBracket=='{')||(potentialBracket=='[')||(potentialBracket=='(')){
                bracketStack.push(potentialBracket);
                lineStack.push(errorLine); // Also push the line number to keep track
            } 
            // Handle closing brackets
            else if ((potentialBracket=='}')||(potentialBracket==']')||(potentialBracket==')')) {
                if (bracketStack.isEmpty() == true){
                    // Error: closing bracket with no matching opening bracket
                    cout << "Bracket Mismatch Detected for " << potentialBracket << " in line " << errorLine << "." << endl;
                    return;  
                }

                char topBracket = bracketStack.peek();

                // Check if the closing bracket matches the last opening bracket
                if ((potentialBracket == '}' && topBracket == '{') ||
                    (potentialBracket == ']' && topBracket == '[') ||
                    (potentialBracket == ')' && topBracket == '(')) {
                    bracketStack.pop();  // Match found, pop the opening bracket
                    lineStack.pop(); // Pop the corresponding line number
                }
                else {
                    // closing bracket does not match the last opening bracket
                    cout << "Bracket Mismatch Detected for " << potentialBracket << " in line " << errorLine << "." << endl;
                    return;
                }
            }
        }
    }
    file.close(); // Close the file after reading
 
    // After reading the entire file, check if there are any unmatched opening brackets
    if (!bracketStack.isEmpty()){
        cout << "Bracket Mismatch Detected for " << bracketStack.peek() << " in line " << lineStack.peek() << "." << endl;
        return;
    }
    else{
        // All brackets matched correctly
        cout << "Ok, Brackets Match!" << endl;
    }
} 



// Function to check matching brackets using linked lists
void BracketChecker::checkList(char* argv) { 
    int errorLine = 0;
    DSStack_LinkedList<int> lineStackList; // Stack to remember line numbers where brackets were pushed (using LinkedList)
   
    ifstream file(argv); // Open the input file

    // Check if the file can be opened correctly
    if (!file.good()) {
        throw invalid_argument("file could not be opened");
    }

    string line;

    // Loop through each line of the file
    while (getline(file,line)){
        errorLine++;

        // Check each character in the line for potential brackets
        for (char potentialBracket : line){
            
            // Push opening brackets onto the stack
            if ((potentialBracket=='{')||(potentialBracket=='[')||(potentialBracket=='(')){
                bracketStackList.push(potentialBracket);
                lineStackList.push(errorLine); // Also push the line number to keep track
            } 
            // Handle closing brackets
            else if ((potentialBracket=='}')||(potentialBracket==']')||(potentialBracket==')')) {
                if (bracketStackList.isEmpty() == true){
                    // Error: closing bracket with no matching opening bracket
                    cout << "Bracket Mismatch Detected for " << potentialBracket << " in line " << errorLine << "." << endl;
                    return;
                }

                char topBracket = bracketStackList.peek();

                // Check if the closing bracket matches the last opening bracket
                if ((potentialBracket == '}' && topBracket == '{') ||
                    (potentialBracket == ']' && topBracket == '[') ||
                    (potentialBracket == ')' && topBracket == '(')) {
                    bracketStackList.pop();  // Match found, pop the opening bracket
                    lineStackList.pop(); // Pop the corresponding line number
                }
                else {
                    //closing bracket does not match the last opening bracket
                    cout << "Bracket Mismatch Detected for " << potentialBracket << " in line " << errorLine << "." << endl;
                    return;
                }
            }
        }
    }

    file.close(); // Close the file after reading

    // After reading the entire file, check if there are any unmatched opening brackets
    if (!bracketStackList.isEmpty()){
        cout << "Bracket Mismatch Detected for " << bracketStackList.peek() << " in line " << lineStackList.peek() << "." << endl;
        return;
    }
    else{
        // All brackets matched correctly
        cout << "Ok, Brackets Match!" << endl;
    }
}
