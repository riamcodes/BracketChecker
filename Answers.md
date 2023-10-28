# Assignment 3: Answers

**Complete this document, commit your changes to Github and submit the repository URL to Canvas.** Keep your answers short and precise.

Your Name:Ria Mukherji

Used free extension: [ ] 24 hrs or [ ] 48 hrs

[X] Early submission (48 hrs)

[ ] Bonus work. Describe: ...

Place [x] for what applies.


## Answers
1. How long did the program take to check all three test files with each version?  Describe what differences in run time you expect for your implementation (use Big-O notation).

   > To check all three files using DSStack it took 4514 microseconds. To check all three using DSS list it took 2184 microseconds. I didn't expect the differences for the run time to be much because these two should have the same big oh notation of O(nm). Each line in the file is n and each character in the line is m for my bracket checking function. The complexity for a list stack and an array stack is O(1) so overall that leaves us with O(nm).

2. Discuss the difference in memory usage based on **your** implementation.

  Array-based Stack Implementation (DSStack):
  Starts with a fixed size of INITIAL_CAPACITY which is at 100 upon initialization, it allocates memory for 100 elements regardless of whether used or not. When my stack reaches capacity it can not resize itself and will fail which is not good. I wrote a resize function for it, but if I resize it, that is very costly and slow for my program.
  Minimal overhead with no extra pointers. Memory is in order also instead of allocated in scattered areas and having to follow pointers.

Linked-list based List Implementation (DSList):
Dynamic Size: The linked list is a singly linked list grows and shrinks as needed. It only allocates memory for the elements added.
Each element iequires a node, which has both the value and a pointer to the next node which could create overhead.
Since nodes are individually allocated this could lead to more fragmented memory.
One thing thats bad is that when trying to access the last element there is no tail pointer so I have to loop through the entire linked list following pointer to pointer which seems like it would be slow.

3. Which version would you use in practice. Why?

   > The linked list was faster so I would use that. It also allows for a size that can change easily if I don't know how many elements I have which the array based stack does not. I would not want my array to have to double or have a bunch of unused wasted memory which is why I would choose the linked list.

4. Make sure that your stack implementations does not have memory leaks.

   ```
   Paste the output of valgrind for running your tests for `DSStack_array` and `DSStack_list` here. 
   test_DSStack.cpp: 
 ==31509== 
==31509== HEAP SUMMARY:
==31509==     in use at exit: 0 bytes in 0 blocks
==31509==   total heap usage: 2,721 allocs, 2,721 frees, 457,820 bytes allocated
==31509== 
==31509== All heap blocks were freed -- no leaks are possible
==31509== 
==31509== For lists of detected and suppressed errors, rerun with: -s
==31509== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
rmukherji@genuse54.engr.smu.edu$ 
   ```

test_DSList.cpp: 
All tests passed (54 assertions in 1 test case)

==37757== 
==37757== HEAP SUMMARY:
==37757==     in use at exit: 0 bytes in 0 blocks
==37757==   total heap usage: 102,904 allocs, 102,904 frees, 2,059,442 bytes allocated
==37757== 
==37757== All heap blocks were freed -- no leaks are possible
==37757== 
==37757== For lists of detected and suppressed errors, rerun with: -s
==37757== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
rmukherji@genuse54.engr.smu.edu$ 


5. Did you attempt any bonuses? If so, please give a brief description of what you did.

   >Not yet
