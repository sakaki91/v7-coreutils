#include <stdio.h>
#include <stdlib.h>

// touch - v1.3
// Copyright (C) by Sakaki, 2026.
// LICENSE: BSD 3-Clause License <https://opensource.org/license/bsd-3-clause>

int main(int argc, char *argv[]){
    FILE *new_file;
    if (argc < 2){
        fprintf(stderr, "usage: touch <file>\n");
        exit(EXIT_FAILURE);
    } else {
        for(int i = 1; i < argc; i++){
            new_file = fopen(argv[i], "a");
            if (new_file == NULL){
                perror("touch");
                exit(EXIT_FAILURE);
            }  
        }
        fclose(new_file);
    }
    return 0;
}
