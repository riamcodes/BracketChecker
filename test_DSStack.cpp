#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "DSStack.h"


// add includes


TEST_CASE("Check that DSStack works", "[DSStack]")
{
    // add test cases (create lists and specify what the expected output is)

   DSStack<char> stack1;
   std:: cout << stack1.isEmpty();

   //initialized stack should be empty
   REQUIRE(stack1.isEmpty() == true); //passed

   //push a
    stack1.push('a');
    std:: cout << stack1.isEmpty();

    //tests stack no longer empty
    REQUIRE(stack1.isEmpty() == false);//passed 


    std :: cout << stack1.peek();
   //peek only looks at the top
   REQUIRE(stack1.isEmpty() == false); //passed


    std :: cout << stack1.pop();

    //pop removed the element 
     REQUIRE(stack1.isEmpty() == true);//passed 


      stack1.push('a');
      stack1.push('b');
      stack1.push('c');
      stack1.push('d');
     REQUIRE(stack1.pop() == 'd');
      stack1.push('e');
               //  stack1.print();
      
   DSStack<int> originalStack;

    originalStack.push(1);
    originalStack.push(2);
    originalStack.push(3);

        DSStack<int> copiedStack(originalStack);

        // The copied stack should have the same values
        REQUIRE(copiedStack.pop() == 3);
        REQUIRE(copiedStack.pop() == 2);
        REQUIRE(copiedStack.pop() == 1);
        REQUIRE(copiedStack.isEmpty() == true);

        // The original stack should not be affected
        REQUIRE(originalStack.pop() == 3);
        REQUIRE(originalStack.pop() == 2);
        REQUIRE(originalStack.pop() == 1);
        REQUIRE(originalStack.isEmpty() == true);


        DSStack<int> testStack;
        testStack.push(1);
        testStack.push(2);
        testStack.push(3);

        DSStack<int> stack2;
       stack2 = testStack;

        // The assigned stack should have the same values
        REQUIRE(testStack.pop() == 3);
        REQUIRE(testStack.pop() == 2);
        REQUIRE(testStack.pop() == 1);
        REQUIRE(testStack.isEmpty() == true);

        // The original stack should not be affected
          REQUIRE(stack2.isEmpty() == false);
      
    }

