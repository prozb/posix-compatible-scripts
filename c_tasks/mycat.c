/***************************************
 *      @author Pavlo Rozbytskyi       *
 *      @date 14/05/2019               *
 ***************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWLEN 5

int getl(char *, int);
void print_line(char *);

int main(void){
    int current_len = 0;
    char s[MAXWLEN];

    while ((current_len = getl(s, MAXWLEN)) != 0){
        print_line(s);
    }    
    return 0;
}

void print_line(char *line){
    char *word = line; 

    while(*word != '\0'){
        putchar(*word);
        word++;
    }
}

int getl(char *line, int size){
    int len = 0;
    char ch;
    char *new_line = line;

    ch = getchar();
    size--;

    if(ch == EOF)
        return 0;
    
    while (ch != EOF && ch != '\n' && len < size){
        *new_line = ch;
        new_line++;    
        len++;  

        if(len < size){
            ch = getchar();
        }  
    }

    if(ch == '\n' && len < size){
        *new_line = '\n';
        new_line++;
        *new_line = '\0';
        len += 2;
    }else{
        *new_line = '\0';
        len++;
    }

    return len;
}