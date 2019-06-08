#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "getline.c" 

typedef struct string_t{
	size_t	len;
	char	*str;
}string_t;

// pushing line on the stack
int push_line(char *);
// compares first and second parameter. 
// If > 0 => first parameted greater than second
int comparator(const void *, const void *);
int comparator_reverse(const void *, const void *);

static int r_flag;
static int size;
static string_t *lines;

int main(int argc, char *argv[]){
    if (argc > 1 && strcmp("-r", argv[1]) == 0){
        r_flag = 1;
    }

    size  = 1;
    lines = malloc(size * sizeof(string_t));

    char *line = NULL;
    size_t len = 0;
    int nread;

    while ((nread = getline(&line, &len, stdin)) > 0){
        push_line(line);
    }

    if(r_flag){
        qsort(lines, (size - 1), sizeof(string_t), comparator_reverse);
    }else{
        qsort(lines, (size - 1), sizeof(string_t), comparator);
    }

    for(int i = 0; i < (size - 1); i++){
        printf("%s", (lines + i)->str);
    }
    
    free(lines);
    
    return 0;
}

int push_line(char *line){
    int line_len = strlen(line);
    string_t *line_record = malloc(sizeof(string_t));

    if(line_record != NULL){
        line_record->len = line_len;
        line_record->str = malloc(line_len * sizeof(char));

        if(line_record->str != NULL){
            strcpy(line_record->str, line);
        }else{
            free(line_record);
            free(lines);
            exit(1);
        }

        lines[size - 1] = *line_record;
        lines = realloc(lines, ++size * sizeof(string_t));

        if(lines == NULL){
            free(line_record);
            exit(1);
        }
    }else{
        free(lines);
        exit(1);
    }

    return 0;
}

int comparator(const void *line_str1 , const void *line_str2){
    const string_t *str1 = (const string_t *)line_str1; 
    const string_t *str2 = (const string_t *)line_str2;

    return str1->len - str2->len;
}

int comparator_reverse(const void *line_str1 , const void *line_str2){
    const string_t *str1 = (const string_t *)line_str1; 
    const string_t *str2 = (const string_t *)line_str2;

    return str2->len - str1->len;
}