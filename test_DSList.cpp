
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "DSList.h"


//All test cases pass. Every function is checked. Edge cases are checked. Exceptions are checked 
TEST_CASE("DSList functionality", "[DSList]")
{
    SECTION("Initialization and basic operations")
    {
        DSList<int> list;

        // A newly created list should be empty
        REQUIRE(list.isEmpty() == true);

        // Pushing an element to the front of the list
        list.push_front(10);
        REQUIRE(list.isEmpty() == false);
        REQUIRE(list.size() == 1);
        REQUIRE(list.find(10) == 0);

        // Pushing an element to the back of the list
        list.push_back(20);
        REQUIRE(list.size() == 2);
        REQUIRE(list.find(20) == 1);
    }

    SECTION("Push and pop operations")
    {
        DSList<char> list;

        list.push_front('a');
        list.push_back('b');
        list.push_back('c');

        REQUIRE(list.size() == 3);
        REQUIRE(list.find('a') == 0);
        REQUIRE(list.find('b') == 1);
        REQUIRE(list.find('c') == 2);

        list.pop_front();
        REQUIRE(list.size() == 2);
        REQUIRE(list.find('a') == -1);

        list.pop_back();
        REQUIRE(list.size() == 1);
        REQUIRE(list.find('c') == -1);

        list.push_front('d');
        REQUIRE(list.size() == 2);
        REQUIRE(list.find('d') == 0);  // 'd' should now be at the front of the list
        REQUIRE(list.find('b') == 1);  // 'b' should now be at index 1
    }

    SECTION("Copy constructor")
    {
        DSList<int> originalList;
        originalList.push_back(1);
        originalList.push_back(2);
        originalList.push_back(3);

        DSList<int> copiedList(originalList);

        REQUIRE(copiedList.size() == 3);
        REQUIRE(copiedList.find(1) == 0);
        REQUIRE(copiedList.find(2) == 1);
        REQUIRE(copiedList.find(3) == 2);

        copiedList.pop_back();
        REQUIRE(copiedList.find(3) == -1);
        REQUIRE(originalList.find(3) == 2); // The original list should not be affected
    }

    SECTION("Copy assignment operator")
    {
        DSList<int> list1;
        list1.push_back(1);
        list1.push_back(2);
        list1.push_back(3);

        DSList<int> list2;
        list2 = list1;

        REQUIRE(list2.size() == 3);
        REQUIRE(list2.find(1) == 0);
        REQUIRE(list2.find(2) == 1);
        REQUIRE(list2.find(3) == 2);

        list2.pop_front();
        REQUIRE(list2.find(1) == -1);
        REQUIRE(list1.find(1) == 0); // The original list should not be affected
    }

    SECTION("Clearing the list")
    {
        DSList<int> list;
        list.push_back(10);
        list.push_back(20);
        list.push_back(30);

        REQUIRE(list.size() == 3);
        list.clearList();
        REQUIRE(list.isEmpty() == true);
    }

    SECTION("Find method")
    {
        DSList<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        list.push_back(2); // Duplicate value

        REQUIRE(list.find(1) == 0);
        REQUIRE(list.find(2) == 1); // Should return the index of the first occurrence
        REQUIRE(list.find(3) == 2);
        REQUIRE(list.find(4) == -1); // Not in the list
    }
  
    SECTION("Large numbers")
    {
        DSList<int64_t> list;
        int64_t largeNumber = 9223372036854775807;  // Max value of int64_t

        list.push_back(largeNumber);
        REQUIRE(list.find(largeNumber) == 0);

        list.push_front(-largeNumber);
        REQUIRE(list.find(-largeNumber) == 0);
    }

    SECTION("Negative numbers")
    {
        DSList<int> list;

        list.push_back(-1);
        list.push_back(-100);
        list.push_back(-1000);

        REQUIRE(list.size() == 3);
        REQUIRE(list.find(-1) == 0);
        REQUIRE(list.find(-100) == 1);
        REQUIRE(list.find(-1000) == 2);
    }

    SECTION("Edge cases")
    {
        DSList<int> list;

        // Adding and removing single element
        list.push_back(5);
        REQUIRE(list.size() == 1);
        list.pop_back();
        REQUIRE(list.isEmpty() == true);

        list.push_front(5);
        REQUIRE(list.size() == 1);
        list.pop_front();
        REQUIRE(list.isEmpty() == true);

        // Popping from an empty list
        REQUIRE_THROWS_AS(list.pop_back(), std::runtime_error);
        REQUIRE_THROWS_AS(list.pop_front(), std::runtime_error);

        // Finding in an empty list
        REQUIRE(list.find(5) == -1);
    }

    SECTION("Extensive operations")
    {
        DSList<int> list;

        // Add large number of elements
        for(int i = 0; i < 100000; i++)
        {
            list.push_back(i);
        }
        REQUIRE(list.size() == 100000);
        REQUIRE(list.find(0) == 0);
        REQUIRE(list.find(99999) == 99999);

        // Remove large number of elements
        for(int i = 0; i < 50000; i++)
        {
            list.pop_back();
        }
        REQUIRE(list.size() == 50000);
        REQUIRE(list.find(99999) == -1);
        REQUIRE(list.find(49999) == 49999);
    }

}
