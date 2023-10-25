
#include <iostream>
#include <algorithm>
#include <chrono>

#include "DSList.h"
#include "DSStack.h"
#include "BracketChecker.h"

using namespace std;

int main(int argc, char **argv)
{
    BracketChecker bc;

    // Start timer for bc.checkArray
    auto start_time_checkArray = chrono::high_resolution_clock::now();

    bc.checkArray(argv[1]);

    // End timer for bc.checkArray
    auto end_time_checkArray = chrono::high_resolution_clock::now();
    auto duration_checkArray = chrono::duration_cast<chrono::microseconds>(end_time_checkArray - start_time_checkArray).count();

    // Start timer for bc.checkList
    auto start_time_checkList = chrono::high_resolution_clock::now();

    bc.checkList(argv[1]);

    // End timer for bc.checkList
    auto end_time_checkList = chrono::high_resolution_clock::now();
    auto duration_checkList = chrono::duration_cast<chrono::microseconds>(end_time_checkList - start_time_checkList).count();

    cout << endl;

    for (int i = 1; i < argc; ++i)
    {
        cout << argv[i] << " - this took " << duration_checkArray + duration_checkList << " microseconds)\n";
    }
    
    cout << "Checking using DSSTack: " << duration_checkArray << " microseconds" << endl;
    cout << "Checking using DSList: " << duration_checkList << " microseconds" << endl;

    return 1;
}




