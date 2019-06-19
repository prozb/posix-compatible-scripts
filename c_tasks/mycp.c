#include <stdio.h>
#include <sys/stat.h> 
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define BUFFER_SIZE 256

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
