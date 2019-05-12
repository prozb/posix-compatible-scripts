#include <stdio.h>
#include <ctype.h>

int print_ascii(void);

int main(int argc, char *argv[]) {
    print_ascii();

    return 0;
}

int print_ascii(void){
    char *table_header = "Oct Dec Hex Chr\n---------------";

    // clear terminal 
    clear();

    for (int i = 0; i < 127; i++){
        if(i == 0 || i == 32 || i == 64 || i == 116 || i == 150){
            // printing new table header
            printf("%s\n", table_header);

        }
        
        printf("%03o %-3d %-3x ", i, i, i);

        if(isprint(i)){
            printf("%-3c\n", i);
        }else{
            printf("\n");
        }
    }

    return 0;
}