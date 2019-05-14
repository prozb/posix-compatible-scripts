#include <stdio.h>
#include <ctype.h>

#define MAXWLEN 129
#define DEBUG 

int process_word(char []);
int read_next_word(char [], int);
void print_word(char []);

char word_0[MAXWLEN] = {'\0'};
char word_1[MAXWLEN] = {'\0'};
char word_2[MAXWLEN] = {'\0'};

int main(void){
    char current_word[MAXWLEN];
    int current_len = 0;
    // int current_max = 0;

    while ((current_len = read_next_word(current_word, MAXWLEN)) != 0){
        printf("%d ", current_len);
        print_word(current_word); 
    }    

    return 0;
}

void print_word(char word[]){
    // #ifdef DEBUG 
    //     printf("word: ");
    // #endif

    for(int i = 0; i < MAXWLEN - 1 && word[i] != '\0'; i++){
        printf("%c", word[i]);
    }
    printf("\n");

    // #ifdef DEBUG 
    // #endif
}

int read_next_word(char buf[], int buf_len){
    int len = 0;
    char current_char = getchar();

    // printf("debug here: %c\n", current_char);

    while(current_char != EOF && current_char != ' ' && current_char != '\0'){
        // ignoring all not printable

        if(isgraph(current_char)){
            // push to buffer if size < 129
            if(len < buf_len - 1){
                // printf("pushing: %c\n", current_char);

                buf[len++] = current_char;
            }else{
                len++;
            }
        }
        current_char = getchar();
    }

    // printf("size return: %d\n", len);
    // setting null byte
    buf[len] = '\0';

    return len;
}

