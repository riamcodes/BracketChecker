# Assignment 3: Answers

**Complete this document, commit your changes to Github and submit the repository URL to Canvas.** Keep your answers short and precise.

Your Name:Ria Mukherji

Used free extension: [ ] 24 hrs or [ ] 48 hrs

[X] Early submission (48 hrs)

[ ] Bonus work. Describe: ...

Place [x] for what applies.


## Answers
1. How long did the program take to check all three test files with each version?  Describe what differences in run time you expect for your implementation (use Big-O notation).

   > Your answer

2. Discuss the difference in memory usage based on **your** implementation.

   > Your answer

3. Which version would you use in practice. Why?

   > Your answer

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

   > Your answer
