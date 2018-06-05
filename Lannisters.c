/*
You are an entry level hero and your first task from the Lannisters of Justice is to break into the throne room of the Mad Mathemagician. The only issue is that his throne is guarded by a numeric password that is solved by following a specific ordering of operations on an expression. 

No one before you was successful, but that was because they didn't figure out that the Mathemagician followed his own Mad order of operations; he ordered it by the amount of strokes it took his iron pen to write the operators. The ordering you have deduced (from first to last) is: subtraction( - ), division( / ), addition( + ), multiplication( * )


Input Specifications
You will be given a single line of character input of no more than 100 characters that is a valid math expression using integers and math operations. Example could be something as simple as 3+4 or something a little more complex, such as 3*4+12/6. Your input will only contain the 4 operators and numbers, no other characters.


Output Specifications
You will need to output the solution to the equation when applying the Mathemagician's order of operations. All output will be a single integer value.
*/

//Problem        : Lannisters of Justice
//Language       : C
//Compiled Using : GCC
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
int MAXSIZE = 100;       
int stack[100];     
int top = -1;            

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return stack[top];
}

int pop() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Stack is empty.\n");
   }
}

int push(int data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Stack is full.\n");
   }
}
int main() {
    
     char input[100];
     scanf("%s",input);
     
   
     
     int len;
     len = strlen(input);
     int array_of_input[len];
     int i;
     int sum;
     sum = 0;
     int index;
     index = 0;
     int exponent;
     exponent = 0;
     
     for (i=len-1; i>= 0; --i){
        
         if((int) input[i] == 42 || (int) input[i] == 43 || (int) input[i] == 47 || (int)input[i] ==45){
             array_of_input[index++] = sum;
            sum =0;
            exponent =0;
            array_of_input[index++] = (int)input[i];
         }
         else{
             sum += ((int) input[i] - 48) * pow(10,exponent++);
         }
         
     }
     array_of_input[index] = sum;
     int j;
     
     for(j=index; j>=0; j--){
         if( array_of_input[j] == 45){
          int first = pop();
          int second = array_of_input[j-1];
          int result = first - second;
          push(result);
          j-=1;
         }
         else{
             push(array_of_input[j]);
         }
     }
     

     
    int track;
    track = 0;
    int reverse_stack1[len];
    while(!isempty()){
         reverse_stack1[track++] = pop();
     } 
       int iman;
       for(iman=track-1; iman>=0; iman--){
         if(reverse_stack1[iman] == 47){
          int f = pop();
          int sd = reverse_stack1[iman-1];
          int result = f / sd;
          push(result);
          iman-=1;
         }
         else{
             push(reverse_stack1[iman]);
         }
     }
     
        int track2 = 0;
  
    int reverse_stack2[len];
    while(!isempty()){
         reverse_stack2[track2++] = pop();
     } 
     int iman2;
       for(iman2=track2-1; iman2>=0; iman2--){
         if(reverse_stack2[iman2] == 43){
          int frst = pop();
          int scond = reverse_stack2[iman2-1];
          int reslt = frst + scond;
          push(reslt);
          iman2-=1;
         }
         else{
             push(reverse_stack2[iman2]);
         }
     }
    
     
    int track3 =0;
    int reverse_stack3[len];
    while(!isempty()){
         reverse_stack3[track3++] = pop();
     } 
     int iman3;
       for(iman3=track3-1; iman3>=0; iman3--){
         if(reverse_stack3[iman3] == 42){
          int fi = pop();
          int se = reverse_stack3[iman3-1];
          int resul = fi * se;
          push(resul);
          iman3-=1;
         }
         else{
             push(reverse_stack3[iman3]);
         }
     }
      while(!isempty()){
         printf("%i\n",pop()); 
     } 
     
     
     
 
     
     
     
     
   
    

    return 0;
}


     
