/******************************************
 *  Program for solving expressions in    *
 *  reverse polish notation               *
 *  @autor: Pavlo Rozbitski               *
 *  @date: 01.06.2019                     *
 *****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STACK_SIZE 2
#define ADD "+"
#define SUB "-"
#define DIV "/"
#define MUL "*"
#define POW "^"
#define RUN_TESTS

int push(double);
int pop(double *);
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
    if(pop(&res) != 0 && get_size() != 0)
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
    double op1, op2, res;

    if(pop(&op1) != 0 || pop(&op2) != 0)
        return 1;

    if(strcmp(op, ADD) == 0){
        res = op1 + op2;
    }else if(strcmp(op, SUB) == 0){
        res = op2 - op1;
    }else if(strcmp(op, MUL) == 0){
        res = op2 * op1;
    }else if(strcmp(op, DIV) == 0){
        if(op1 == 0)
            return 1;
        res = op2 / op1;
    }else if(strcmp(op, POW) == 0){
        if(op2 < 0 && ceilf(op1) != op1)
            return 1;
        res = pow(op2, op1);
    }else{
        return 1;
    }

    if(push(res) != 0)
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



