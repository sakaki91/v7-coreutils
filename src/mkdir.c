#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

// mkdir - v1.1
// Copyright (C) by Sakaki, 2026.
// LICENSE: BSD 3-Clause License <https://opensource.org/license/bsd-3-clause>

int main(int argc, char *argv[]){
    if (argc < 2){
        fprintf(stderr, "usage: mkdir <directory>\n");
        exit(EXIT_FAILURE);
    } else {
        for (int i = 1; i < argc; i++){
            if (mkdir(argv[i], 0755) == -1){
                perror("mkdir");
            }
        }
    }
    return 0;
}
