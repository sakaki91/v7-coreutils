#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

// l - v1.00
// Copyright (C) by Sakaki, 2026.
// LICENSE: BSD 3-Clause License <https://opensource.org/license/bsd-3-clause>

int main(int argc, char *argv[]){
    DIR *dir;
    struct dirent *entry;
    if (argc < 2){
        dir = opendir(".");
        while((entry = readdir(dir)) != NULL){
            printf("%s\n", entry->d_name); 
        }
        closedir(dir);
    } else if (argc > 1){
        dir = opendir(argv[1]);
        if (dir == NULL){
            printf("error: no such file or directory.\n");
            exit(EXIT_FAILURE);
        }
        while((entry = readdir(dir)) != NULL){
            printf("%s\n", entry->d_name);
        }
        closedir(dir);
    }
    return 0;
}
