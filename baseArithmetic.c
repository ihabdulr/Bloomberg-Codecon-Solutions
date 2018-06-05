/*
PROBLEM

A base-n number is a number that is made up of at most n symbols -
Base-2 is a number with 0s and 1
Base-10 is a number with digits in {0,1,2,3,4,5,6,7,8,9}
Base-16 is a number with digits 0-9,A-F etc

For this problem, you are required to do the following:
Given a number X (X will be a number in a base between base-2 and base-16), find the minimum base that can be associated with X.
Example: The minimum base associated 385 is base-9 (as it needs to have a base that supports the digit 8 which is its highest value digit). Similarly, the minimum base associated with B95 is base-12.

Convert X from this base to a value X_10 in base-10.

Do the same for another number Y and call its value in base-10 as Y_10

Print out the sum of these two numbers in base-10, ie X_10 + Y_10

Input Specifications
Your program will take
A number X in base-m (X >= 0, 2 ≤ m ≤ 16)

A number Y in base-n (Y >= 0, 2 ≤ n ≤ 16)

You can assume that X and Y when converted to base-10 will fit in a long long (C++).

Output Specifications
Based on the input, print out the sum of X_10 and Y_10

*/ 

//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT
#include <stdio.h>
#include <math.h>


int determine_base (char number[]);

int ascii_to_base (int number);

int calculate_total (int base, char number[]);

ascii_to_base(int number){
    if (number >= 48 && number <= 57)
        return number - 48;
    else if (65 <= number && number <= 71)
        return number - 55;
   
}

determine_base (char number[]){
    
    int i, largest_val = 0, size = strlen(number);
    
    for( i = 0; i<size; i++)
        if((int) number[i] > (int) largest_val)
            largest_val = number[i];
       
    return ascii_to_base((int) largest_val + 1);
}

calculate_total(int base, char number[]){
    
    int i, size = strlen(number), exponent = 0;
    
    long long sum = 0;

    for (i = size-1; i >= 0; i--)
        sum += ascii_to_base((int)number[i]) * pow(base,exponent++);
    
    return sum;
}


int main() {

   char X[99999];
   char Y[99999];
   
   scanf("%s",X);
   scanf("%s",Y);
   long long X_10 = calculate_total(determine_base(X),X);
   long long Y_10 = calculate_total(determine_base(Y),Y);
   printf("%lld", X_10 + Y_10);
  
   return 0;
   
}
