#include <stdio.h>
#include <stdlib.h>

// cat - v1.0
// Copyright (C) by Sakaki, 2026.
// LICENSE: BSD 3-Clause License <https://opensource.org/license/bsd-3-clause>

int main(int argc, char *argv[]){
    FILE *read_file;
    char line_size[1024];
    if (argc < 2){
        fprintf(stderr, "usage: cat <file>\n");
        exit(EXIT_FAILURE);
    } else {
        read_file = fopen(argv[1], "r");
        if(read_file == NULL){
            perror("cat");
            exit(EXIT_FAILURE);
        }
        while(fgets(line_size, sizeof(line_size), read_file) != NULL){
            printf("%s", line_size);
        }
        fclose(read_file);
    }
    return 0;
}
