// #define CATCH_CONFIG_MAIN
// #include "catch2/catch.hpp"
// #include "DSStack.h"


// // add includes


// TEST_CASE("Check that DSStack works", "[DSStack]")
// {
//     // add test cases (create lists and specify what the expected output is)

//    DSStack<char> stack1;
//    std:: cout << stack1.isEmpty();

//    //initialized stack should be empty
//    REQUIRE(stack1.isEmpty() == true); //passed

//    //push a
//     stack1.push('a');
//     std:: cout << stack1.isEmpty();

//     //tests stack no longer empty
//     REQUIRE(stack1.isEmpty() == false);//passed 


//     std :: cout << stack1.peek();
//    //peek only looks at the top
//    REQUIRE(stack1.isEmpty() == false); //passed


//     std :: cout << stack1.pop();

//     //pop removed the element 
//      REQUIRE(stack1.isEmpty() == true);//passed 


//       stack1.push('a');
//       stack1.push('b');
//       stack1.push('c');
//       stack1.push('d');
//      REQUIRE(stack1.pop() == 'd');
//       stack1.push('e');
//                //  stack1.print();
      
//    DSStack<int> originalStack;

//     originalStack.push(1);
//     originalStack.push(2);
//     originalStack.push(3);

//         DSStack<int> copiedStack(originalStack);

//         // The copied stack should have the same values
//         REQUIRE(copiedStack.pop() == 3);
//         REQUIRE(copiedStack.pop() == 2);
//         REQUIRE(copiedStack.pop() == 1);
//         REQUIRE(copiedStack.isEmpty() == true);

//         // The original stack should not be affected
//         REQUIRE(originalStack.pop() == 3);
//         REQUIRE(originalStack.pop() == 2);
//         REQUIRE(originalStack.pop() == 1);
//         REQUIRE(originalStack.isEmpty() == true);


//         DSStack<int> testStack;
//         testStack.push(1);
//         testStack.push(2);
//         testStack.push(3);

//         DSStack<int> stack2;
//        stack2 = testStack;

//         // The assigned stack should have the same values
//         REQUIRE(testStack.pop() == 3);
//         REQUIRE(testStack.pop() == 2);
//         REQUIRE(testStack.pop() == 1);
//         REQUIRE(testStack.isEmpty() == true);

//         // The original stack should not be affected
//           REQUIRE(stack2.isEmpty() == false);
      
//     }

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "DSStack.h"
#include <climits>

TEST_CASE("DSStack functionality", "[DSStack]")
{
    SECTION("Initialization and basic operations")
    {
        DSStack<int> stack;
        
        // A newly created stack should be empty
        REQUIRE(stack.isEmpty() == true);

        // Pushing an element to the stack
        stack.push(10);
        REQUIRE(stack.isEmpty() == false);
        
        // Peek at the top element without popping it
        REQUIRE(stack.peek() == 10);
        REQUIRE(stack.isEmpty() == false);

        // Pop the element from the stack
        REQUIRE(stack.pop() == 10);
        REQUIRE(stack.isEmpty() == true);
    }

    SECTION("Multiple push and pop operations")
    {
        DSStack<char> stack;
        
        stack.push('a');
        stack.push('b');
        stack.push('c');

        REQUIRE(stack.peek() == 'c');

        REQUIRE(stack.pop() == 'c');
        REQUIRE(stack.pop() == 'b');
        REQUIRE(stack.pop() == 'a');
        REQUIRE(stack.isEmpty() == true);
    }

    SECTION("Copy constructor")
    {
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
    }

    SECTION("Copy assignment operator")
    {
        DSStack<int> testStack;
        testStack.push(1);
        testStack.push(2);
        testStack.push(3);

        DSStack<int> assignedStack;
        assignedStack = testStack;

        // The assigned stack should have the same values
        REQUIRE(assignedStack.pop() == 3);
        REQUIRE(assignedStack.pop() == 2);
        REQUIRE(assignedStack.pop() == 1);
        REQUIRE(assignedStack.isEmpty() == true);

        // The original stack should not be affected
        REQUIRE(testStack.pop() == 3);
        REQUIRE(testStack.pop() == 2);
        REQUIRE(testStack.pop() == 1);
        REQUIRE(testStack.isEmpty() == true);
    }

    SECTION("Exception handling")
    {
        DSStack<int> stack;

        // Test for underflow exceptions
        REQUIRE_THROWS_AS(stack.pop(), std::runtime_error);
        REQUIRE_THROWS_AS(stack.peek(), std::runtime_error);

        // Filling the stack to test overflow exception
        for (int i = 0; i < 50; ++i)
        {
            stack.push(i);
        }

        // The stack should now be full, so pushing should throw an exception
        REQUIRE_THROWS_AS(stack.push(100), std::runtime_error);
    }

       SECTION("Handling of negative, large numbers and other edge cases")
    {
        DSStack<int> stack;

        // Pushing negative values
        stack.push(-1);
        stack.push(-1000);
        stack.push(-1000000);

        REQUIRE(stack.peek() == -1000000);
        REQUIRE(stack.pop() == -1000000);
        REQUIRE(stack.pop() == -1000);
        REQUIRE(stack.pop() == -1);
        REQUIRE(stack.isEmpty() == true);

        // Pushing large values
        stack.push(INT_MAX);
        stack.push(INT_MIN);

        REQUIRE(stack.peek() == INT_MIN);
        REQUIRE(stack.pop() == INT_MIN);
        REQUIRE(stack.peek() == INT_MAX);
        REQUIRE(stack.pop() == INT_MAX);
        REQUIRE(stack.isEmpty() == true);

        // Pushing zero, which could be a boundary case in some scenarios
        stack.push(0);
        REQUIRE(stack.peek() == 0);
        REQUIRE(stack.pop() == 0);
        REQUIRE(stack.isEmpty() == true);
    }
 
}
