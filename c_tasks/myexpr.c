/******************************************
 *  Program for solving expressions in    *
 *  reverse polish notation               *
 *  @autor: Pavlo Rozbitski               *
 *  @date: 01.06.2019                     *
 *****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 2
#define ADD "+"
#define SUB "-"
#define DIV "/"
#define MUL "*"
#define POW "^"
#define RUN_TESTS

int push(double);
int pop(double *);
int exec_add(void);
int exec_sub(void);
int exec_mul(void);
int exec_div(void);
int exec_pow(void);
int get_size();
int exec_operation(char *);
int parse_double(char *, double *);

double stack [STACK_SIZE];
double *top; // next free position on stack
double *bot; // bottom of the stack

int main(int argc, char *argv[]){
    if(argc < 2){
        return 1;
    }

    top = stack;
    bot = stack;

    for(int i = 1; i < argc; i++){
        double var;
        if(parse_double(argv[i], &var) == 0){
            push(var);
        }else if(exec_operation(argv[i]) != 0){
            return 1;
        }
    }
    // printing result 
    double res;
    if(pop(&res) != 0)
        return 1;

    printf("%g\n", res);

    return 0;
}

int parse_double(char *op, double *num){
    double parsed;
    char *end;

    if((((parsed = strtod(op, &end)) == 0) && (end == op)) 
        || (*end != '\0')){
        return 1;
    }
    *num = parsed;

    return 0;
}

int exec_operation(char *op){
    if(strcmp(op, ADD) == 0){
        if(exec_add() != 0)
            return 1;
    }else if(strcmp(op, SUB) == 0){
        if(exec_sub() != 0)
            return 1;
    }else if(strcmp(op, MUL) == 0){
        // todo
    }else if(strcmp(op, DIV) == 0){
        // todo
        // implement zero division checking
    }else if(strcmp(op, POW) == 0){
        // todo
    }else{
        // unpermited operation
        return 1;
    }

    return 0;
}

int exec_add(void){
    double a0, a1, sum;

    if(pop(&a0) != 0 || pop(&a1) != 0)
        return 1;
    
    sum = a0 + a1;

    if(push(sum) != 0)
        return 1;
    return 0;
}

int exec_sub(void){
    double a0, a1, sub;

    if(pop(&a0) != 0 || pop(&a1) != 0)
        return 1;
    
    sub = a1 - a0;

    if(push(sub) != 0)
        return 1;
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



