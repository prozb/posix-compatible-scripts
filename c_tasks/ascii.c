#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    for(int i = 0; i < 5; i++) { printf("Oct Dec Hex Chr   "); }
    printf("\n");
    for(int i = 0; i < 5; i++) { printf("---------------   "); }
    printf("\n");

    for (int i = 0; i < 26; i++){
        // printing each table
        for(int j = 0; j < 5; j++){
            int char_index = i + j * 26;

            if(char_index < 128){
                printf("%03o %3d %3x ", char_index, char_index, char_index);

                if(isprint(char_index)){
                    printf("%3c", char_index);
                }else{
                    printf("   ");
                }
                printf("   ");
            }
        }
        printf("\n\n");
    }

    return 0;
}