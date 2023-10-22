#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "DSList.h"

// add includes


TEST_CASE("Check that DSList works", "[DSList]")
{
    // add test cases (create lists and specify what the expected output is)

    //REQUIRE(0 + 1 == 1);
    // This creates an error
   // REQUIRE(0 == 1);

        DSList<int> list;

    //list originally empty 
    REQUIRE(list.isEmpty() == true); // pass 

    //list size 0 
    REQUIRE(list.size() == 0);//pass

    //push 1 to front 
    list.push_front(1);//pass
    
    //list contains 1. size 1.
    REQUIRE(list.size() == 1); //pass
    //index of 1 =  0
    REQUIRE(list.find(1) == 0);

    // list contains 1, 2.
    list.push_back(2); 

    //list size = 2.
    REQUIRE(list.size() == 2);//pass
    // index of 2 = 1.
    REQUIRE(list.find(2) == 1);//pass


    
    list.pop_front();

    //list contains 2. size of 1.
    REQUIRE(list.size() == 1); //pass
    //no 1 found in list.
    REQUIRE(list.find(1) == -1);//pass

    //push 4 to the back.
    list.push_back(4);
 
    //list contains 2, 4. size 2. 
    REQUIRE(list.size() == 2);

    //pop the back off 
    list.pop_back();

    //list contains 2. size 1.
    REQUIRE(list.size() == 1); //pass
    //4 was removed
    REQUIRE(list.find(4) == -1);//pass



    
    list.push_front(5);
    //list contains 5,2. size 2.
    REQUIRE(list.find(5) == 0);



   list.pop_front();
   //list contains 2. size 1.
   REQUIRE(list.size() == 1);//pass
   REQUIRE(list.find(5) == -1);
 
   
    list.push_back(6);

    //list contains 2, 6.
    REQUIRE(list.find(6) == 1);//pass

    list.pop_back();


    //list contains  2. size 1.
    REQUIRE(list.size() == 1); //pass 
    REQUIRE(list.find(6) == -1); //pass
    REQUIRE(list.find(2) == 0); //pass

    list.push_back(3);
    list.push_back(4);

    //list contains 2,3,4
    REQUIRE(list.size() == 3); //pass 
  
    list.clearList();
   REQUIRE(list.size() == 0);//pass c leared out list now its empty

 //DSList<int> list;


    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
   // DSList<int> list2 = list;
    REQUIRE(list.size() == 3);
    REQUIRE(list.find(2) == 1);

    DSList<int> list2 = list;
    REQUIRE(list2.size() == 3);
    REQUIRE(list2.find(2) == 1);


 list.push_back(4);
  list.push_back(4);
   list.push_back(4);
   list2 = list;
 REQUIRE(list2.size() == 6);


// }



// }
}
