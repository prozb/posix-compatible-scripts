/***************************************
 *      @author Pavlo Rozbytskyi       *
 *      @date 14/05/2019               *
 ***************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWLEN 129
#define DEBUG printf("correct\n");

int read_next_word(char [], int);
void print_word(char []);
void process_word(char [], int);
void print_decreasing(void);

char word_0[MAXWLEN] = {'\0'};
char word_1[MAXWLEN] = {'\0'};
char word_2[MAXWLEN] = {'\0'};

int word0_len = 0;
int word1_len = 0;
int word2_len = 0;

int main(void){
    char current_word[MAXWLEN];
    int current_len = 0;

    while ((current_len = read_next_word(current_word, MAXWLEN)) != 0){
        process_word(current_word, current_len); 
    }    
    print_decreasing();

    return 0;
}

void process_word(char word[], int len){
    //checking word occures twice and ignore this word
    if( (len == word0_len && strcmp(word, word_0) == 0)
     || (len == word1_len && strcmp(word, word_1) == 0 )
     || (len == word2_len && strcmp(word, word_2) == 0)){

        return;
    }

    if(len > word0_len){
        strcpy(word_2, word_1);
        strcpy(word_1, word_0);
        strcpy(word_0, word);

        word2_len = word1_len;
        word1_len = word0_len;
        word0_len = len;
    }else if(len > word1_len){
        strcpy(word_2, word_1);
        strcpy(word_1, word);
        word2_len = word1_len;
        word1_len = len;
    }else if(len > word2_len){
        strcpy(word_2, word);
        word2_len = len;
    }
}

void print_decreasing(void){
    // todo implement printing in decreasing order (size as well)
    if(word0_len != 0){
        printf("%d ", word0_len);
        print_word(word_0);
    }

    if(word1_len != 0){
        printf("%d ", word1_len);
        print_word(word_1);
    }

    if(word2_len != 0){
        printf("%d ", word2_len);
        print_word(word_2);
    }
}

int read_next_word(char buf[], int buf_len){
    int i = 0;
    char current_char;

	// skip leading non-alphabetics:
	while ((current_char = getchar()) != EOF && ! isgraph(current_char));

    --buf_len;
	
    // copy alphabetics into buf[]:
	for (i = 0; current_char != EOF && isgraph(current_char);  ++i, current_char = getchar()){
		if (i < buf_len)
			buf[i] = current_char;
    }
    
    // setting null byte
    if(i < buf_len){
        buf[i] = '\0';
    }else{
        buf[buf_len] = '\0';
    }

    return i;
}
// printing word
void print_word(char word[]){
    for(int i = 0; i < MAXWLEN - 1 && word[i] != '\0'; i++){
        printf("%c", word[i]);
    }
    printf("\n");
}


