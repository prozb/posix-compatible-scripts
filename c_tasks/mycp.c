#include <stdio.h>
#include <sys/stat.h> 
#include <sys/types.h>

int main(int argc, char *argv[]){
    char *path = "getline.c";
    struct stat buf; 
    stat(path, &buf);

    mode_t file_mode = buf.st_mtime;
    
    printf("%x\n", file_mode & __S_IFMT);

    return 0;
}