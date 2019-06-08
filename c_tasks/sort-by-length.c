#include <stdio.h>
#include <string.h>

struct string_t {
	size_t	len;
	char	*str;
};

static int r_flag = 0;

int main(int argc, char *argv[]){
    if (argc > 1 && strcmp("r", argv[1]) == 0){
        r_flag = 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while ((nread = getline(&line, &len, stdin)) != EOF){
        printf("size: %zu, read line: %s", len, line);
        len = 0;
    }

    return 0;
}
