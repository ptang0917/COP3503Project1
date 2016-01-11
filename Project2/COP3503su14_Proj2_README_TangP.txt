COP3503su14_Proj2_TangP
 README file

To compile type:
make 

You should see the following prompt:
g++ -c main.cpp
g++ -c project2.cpp
g++ main.cpp project2.cpp -o project2


After that, then type:
./project2

Known to compile with (from g++ -v): 
gcc version 4.6.4 (Ubuntu/Linaro 4.6.4-1ubuntu1~12.04) 

No special resources needed. 
No configuration needed.

Known Bugs
1) The menu main.cpp would "close" if the following input is not an integers
2) If the user inputs option 7, the content saved to the file created through option 7 is different from the current set.
3) If the user chooses option 10,11, or 12 without inputting a file into the current set, then an infinite loop will occur.
4) If the user chooses silent mode, any file inputted for options 2,3,4,5 will respond with an error message. 



