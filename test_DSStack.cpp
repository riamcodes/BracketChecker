#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "DSStack_Array.h"


// add includes


TEST_CASE("Check that DSStack works", "[DSStack]")
{
    // add test cases (create lists and specify what the expected output is)

   DSStack_Array<char> stack1;
   std:: cout << stack1.isEmpty();
   REQUIRE(stack1.isEmpty() == true); //empty

    stack1.push('a');
    std:: cout << stack1.isEmpty();
    REQUIRE(stack1.isEmpty() == false);
    std :: cout << stack1.peek();
     REQUIRE(stack1.isEmpty() == false);
    std :: cout << stack1.pop();
     REQUIRE(stack1.isEmpty() == true);
     stack1.push('a');
        stack1.push('b');
           stack1.push('c');
              stack1.push('d');
              stack1.pop();
                 stack1.push('e');
                 stack1.print();

     // REQUIRE(stack1.isArrayEmpty() == true); pop == a 
    // This creates an error
}

// you can run the test using Run CTest in the task bar or by running the tests executable. 