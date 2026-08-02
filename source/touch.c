#include <stdio.h>
#include <stdlib.h>

// touch - v1.00
// Copyright (C) by Sakaki, 2026.
// LICENSE: BSD 3-Clause License <https://opensource.org/license/bsd-3-clause>

int main(int argc, char *argv[]){
    FILE *new_file;
    if (argc < 2){
        printf("error: empty value.\n");
        exit(EXIT_SUCCESS);
    } else {
        new_file = fopen(argv[1], "w");
        if (new_file == NULL){
            printf("error: while creating the file.\n");
            exit(EXIT_FAILURE);
        }
        if (fprintf(new_file, "\0") == 0){
            fclose(new_file);
            exit(EXIT_SUCCESS);
        }
    }
    return 0;
}
