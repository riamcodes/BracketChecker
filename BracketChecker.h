#ifndef BRACKETCHECKER_H
#define BRACKETCHECKER_H

# include <map>
# include "DSStack.h"

using namespace std;

class BracketChecker {
public:
    void checkArray();
    void checkList();

private:
//    map<DSString, int> dictionary;
      DSStack<char> bracketStack;
      //DSStack_LinkedList<char> bracketStackList;
};
#endif