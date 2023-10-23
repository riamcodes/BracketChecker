#include <chrono>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "BracketChecker.h"
#include "DSStack.h"
#include <map>
#include <iomanip>


void BracketChecker::checkArray() { 

    //file is read in through passed arg
    std::ifstream file("/users7/cse/rmukherji/assignment-3-do-my-brackets-match-riamuk101/test_data/DSVector_good.h");
    if (!file.good())
    {
           throw std::invalid_argument("file could not be opened");
    }

    //once file is open declare DSStack_Array
    DSStack<char> bracketStack;
    std :: string line; 



}