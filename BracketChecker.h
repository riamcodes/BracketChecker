#ifndef BRACKETCHECKER_H
#define BRACKETCHECKER_H
#include "DSList.h"
#include "DSStack_LinkedList.h"

# include <map>
# include "DSStack.h"

using namespace std;

class BracketChecker {
public:
    void checkArray(char* argv);
    void checkList(char* argv);

private:
//    map<DSString, int> dictionary;
      DSStack<char> bracketStack;
      DSStack_LinkedList<char> bracketStackList;
};
#endif