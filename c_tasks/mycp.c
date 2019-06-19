/***************************************
 *      @author Pavlo Rozbytskyi       *
 *      @date 19/06/2019               *
 ***************************************/
#include <stdio.h>
#include <sys/stat.h> 
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <libgen.h>
#include <string.h>

#define BUFFER_SIZE 256
#define MAX_DIR_LENGTH 256

// recursive creating directories
int _mkdir(const char *path); 

int main(int argc, char *argv[]){
    if(argc < 3){
        fprintf(stderr, "Error: parameters not given\n");
        return 1;
    }

    char buffer [BUFFER_SIZE + 1];

    struct stat source;
    struct stat target;

    int tfd;
    int pfd;

    int s_ret;
    // checking source file exists
    if((s_ret = stat(argv[1], &source)) == -1){
        fprintf(stderr, "Error: \"%s\" file does not exist\n", argv[1]);
        return 1;
    }
    stat(argv[2], &target);

    // creating intermediate directories
    char *dir  = dirname(argv[2]);
    char path[strlen(dir) + 1];
    strcpy(path, dir); 
    strcat(path, "/");

    if(_mkdir(path) != 0){
        return 1;
    }

    // check files equals and do nothing
    if(target.st_dev == source.st_dev && 
       target.st_ino == source.st_ino){
        return 0;
    }
     
    if((tfd = open(argv[1], O_RDONLY)) == -1){
        fprintf(stderr, "Error: cannot open target file \"%s\"\n", argv[1]);
        return 1;
    }
    
    if((pfd = open(argv[2], O_CREAT | O_WRONLY, source.st_mode)) == -1){
        fprintf(stderr, "Error: cannot open target file \"%s\"\n", argv[2]);
        return 1;
    }

    int ret;
    while ((ret = read(tfd, buffer, BUFFER_SIZE)) != EOF && ret != 0){
        buffer[ret] = '\0';
        write(pfd, &buffer, ret);
    }

    close(tfd);
    close(pfd);

    return 0;
}


int _mkdir(const char *dir){
    struct stat dir_stat;
    char buffer [MAX_DIR_LENGTH + 1];

    char *p  = buffer;
    int size = 0;

    memcpy(buffer, dir, MAX_DIR_LENGTH);

    while(*p != '\0' && size < MAX_DIR_LENGTH + 1){
        if(*p == '/'){
            *p = '\0';
            //creating directory if does not exist
            if(stat(buffer, &dir_stat) == -1){
                mkdir(buffer, 0700);
            }

            if(stat(buffer, &dir_stat) == -1){
                fprintf(stderr, "Error: cannot create directory \"%s\"\n", buffer);
                return 1;
            }
            *p = '/';
        }
        p++;
    }
    return 0;
}
