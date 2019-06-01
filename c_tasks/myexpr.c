#include <stdio.h>

#define STACK_SIZE 2

int push(double);
int pop(double *);
int get_size();

double stack [STACK_SIZE];
double *top; // next free position on stack
double *bot; // bottom of the stack

int main(void){
    top = stack;
    bot = stack;

    
        
    return 0;
}

int get_size(){
    return (top - bot);
}

int push(double num){
    if(top < STACK_SIZE + bot){
        *top++ = num;
        return 0;
    }
    return 1;
}

int pop(double *num){
    if(top != bot){
        *num = *(--top);
        return 0; 
    }
    return 1;
}





