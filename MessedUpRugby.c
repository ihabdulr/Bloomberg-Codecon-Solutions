/*
A team of developers from New York visits London and decides to try their hands at Rugby. None of them quite remember the exact rules so they just use the rules of American Football where you can score 2, 3 or 7 points at a time.

When they talk to you afterwards, they tell you that the final score of the game was 38 - 0. After facepalming, you are curious to find all possible ways to score 38 points.

Write a program that, given a score X, prints all possible combinations of the messed up conversions (7 points), tries (3 points), and kicks (2 points) that would make up this score.


Input Specifications
Your program will take a target score between 0 and 222.

Output Specifications
Based on the input, print out one row for each combination of messed up conversions, tries, 
and kicks that would get to that score, each column delimited by a space. The output should be in ascending order of touchdowns, field goals, and then safeties. If the score is not achievable, just output 0 0 0
*/

//Problem        : Messed up Rugby
//Language       : C
//Compiled Using : GCC
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <stdio.h>
#include <stdlib.h>


int print_set (int N);

print_set(int N){
    
   int i, j, k,count = 0;
   for(i = 0; i<N; i++)
        for(j =0; j < N; j++)
            for (k = 0; k<N; k++){
                if ( (i *  7 + j * 3 + k * 2) == N){
                   printf("%i %i %i\n",i,j,k);
                    ++count;
                }
            } 
    if (count==0)
        printf("%i %i %i",count,count,count);

    
    return 0;
}

int main() {

    char score[9999];
    scanf("%s",score);
    int N = atoi(score);
    print_set(N);
    
    return 0;
}
