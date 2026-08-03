#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

// mkdir - v1.0
// Copyright (C) by Sakaki, 2026.
// LICENSE: BSD 3-Clause License <https://opensource.org/license/bsd-3-clause>

int main(int argc, char *argv[]){
    if (argc < 2){
        fprintf(stdout, "usage: mkdir <directory>\n");
        exit(EXIT_FAILURE);
    } else {
        if (mkdir(argv[1], 0755) == -1){
            perror("mkdir");
        }
    }
    return 0;
}
