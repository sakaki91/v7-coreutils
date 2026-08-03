#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// l - v1.01
// Copyright (C) by Sakaki, 2026.
// LICENSE: BSD 3-Clause License <https://opensource.org/license/bsd-3-clause>

void listDirectory(int argc, DIR *dir, struct dirent *entry){
    if (argc > 1){
        if (dir == NULL){
            printf("error: no such file or directory.\n");
            exit(EXIT_FAILURE);
        }
    }
    while((entry = readdir(dir)) != NULL){
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){
            continue;
        }
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}

int main(int argc, char *argv[]){
    DIR *dir;
    struct dirent *entry;
    if (argc < 2){
        dir = opendir(".");
        listDirectory(argc, dir, entry);
    } else if (argc > 1){
        dir = opendir(argv[1]);
        listDirectory(argc, dir, entry);
    }
    return 0;
}
