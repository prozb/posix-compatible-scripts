#include <stdio.h>
#define MAX_SIZE 129

int numq(int *, int *, int **, int **, int, int);

int main(void){
    int buffer [MAX_SIZE];

    int *buf_start;
    int *buf_end;

    buf_start = (buffer + 0);
    buf_end   = (buffer + 1);
    
    int **buf_start_point = &buf_start;
    int **buf_end_point   = &buf_end;

    int var;

    while(scanf("%i", &var) != EOF){
        numq(buffer, &buffer[MAX_SIZE - 1], buf_start_point, buf_end_point, var, 0);
    }

    printf("\n");
    (*buf_start_point)++;
    for(int i = 0; i < 4; i++){
        int len = numq(buffer, &buffer[MAX_SIZE - 1], buf_start_point, buf_end_point, 0, 1);
        
        if(len != -1){
            printf("%d\n", *((*buf_start_point) - 1)); 
        }else{
            break;
        }
    }
}

// int *start_stack pointer to start array 
// int *end_stack pointer to end array
// int **oldest_entry pointer to oldest saved entry
// int **next_free pointer to next free address
// int inp next value to enter queue
// int subs if non-zero, function will remove oldest entry before entering next,
int numq(int *start_stack, int *end_stack, int **oldest_entry, int **next_free, int inp, int subs){
    // substitute modus
    if(subs > 0)
    {   
        // check not empty
        if(*oldest_entry == *next_free){
            return -1;
        }
        
        // wrap around
        if(*oldest_entry == end_stack){
            *oldest_entry = start_stack;
        }else{
            (*oldest_entry)++;
        }
        return *next_free - *oldest_entry;
    }else{
        // adding modus
        // check not full
        if(*next_free == *oldest_entry - 1 ||
            (*oldest_entry == start_stack) && (*next_free == end_stack)){   
            return -1;
        }

        if(*next_free == end_stack)
        {
            *end_stack = inp;
            *next_free = start_stack;
        }else{  
            **next_free = inp; 
            (*next_free)++;                    
        }

        return *oldest_entry - *next_free - 1;
    }
}