/*
As part of a team project to build an instant messaging program, you have to work around your teammate's buggy compliance filter.

The compliance filter works based on an algorithm which determines if certain messages can pass through the system and if they should be flagged. Usually the compliance filter system has a dictionary of black listed words which it filters out.

However, due to your teammate's programming error the compliance filter system appears to only allow words that are palindromes or anagrams of palindromes (i.e. can make a palindrome when re-arranged).

For example:

abba
aabb (this one is an anagram of abba or baab)
civic
deified
mom
mmo
radar
While a fix is being worked on, you are tasked with writing an add on that will determine if a word can pass through the this system.


Input Specifications
Your program will take
A string S denoting the word to be tested. All letters in the alphanumeric input will be lowercase (1 ≤ LENGTH(S) ≤ 500), and there may be numbers and symbols.

Output Specifications
Based on the input,
Print out yes if the input would pass through the system
Print out no if the input would fail the system

*/

//Problem        : A Compliance Problem
//Language       : C
//Compiled Using : GCC
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <stdio.h>

int isPalindrome (char str[]);

isPalindrome (char str[]){

   if (strlen(str) == 1)
      return 1;
   int count[256], i,j,k, odds = 0;
   
   for (i = 0; i< 256; ++i){
       count[i] = 0;
   }
   for (j=0; j<strlen(str); ++j){
     count[(int)str[j]]++;
   }
   for (k=0; k<256; ++k){
     if(count[k] %2 == 1)
        ++odds;
   }
   
   return ((strlen(str)%2 ==0 && odds == 0) || (strlen(str)%2 == 1 && odds == 1));
   

}

int main() {

char S[500];
scanf("%s",S);
int y = isPalindrome(S);
if (y == 1)
   printf("%s", "yes");
else 
   printf("%s", "no");
      
return 0;  

}
