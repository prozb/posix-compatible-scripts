#include <stdio.h>

int numq(int *, int *, int **, int **, int, int);
int push(int);
int pop(void);

int main(void){
    int buffer [4] = {1,2,3,4};

    int a = 11;
    
    int *buf_start;
    int *buf_end;

    buf_start = (buffer + 2);
    buf_end   = (buffer + 3);
    
    int **buf_start_point = &buf_start;
    int **buf_end_point   = &buf_end;

    int len;

    len = numq(buffer, &buffer[3], buf_start_point, buf_end_point, a++, 0);
    len = numq(buffer, &buffer[3], buf_start_point, buf_end_point, a++, 0);
    len = numq(buffer, &buffer[3], buf_start_point, buf_end_point, a++, 0);
    
    for(int i = 0; i < 4; i++){
        printf("%d\n", buffer[i]);
    }

    printf("%d\n", len);
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

    // adding modus 
    }
    else
    {
        // check not full
        if(*next_free == *oldest_entry - 1 ||
           (*oldest_entry == start_stack) && (*next_free == end_stack))
        {   
            return -1;
        }else{
            if(*next_free == end_stack)
            {
                *end_stack   = inp;
                *next_free  = start_stack;
            }else{  
                **next_free = inp; 
                (*next_free)++;                
            }
            
            // todo fix size
            return *next_free - *oldest_entry;   
        }
         
    }
    // if(*ca == *cx || *cx == *ca - 1 ||
    //   (*ca == ba) && (*cx == bx - 1))
    // {
    //     return -1;
    // }
    // if pushing to full queue or pop from empty
    

    return 0;
}