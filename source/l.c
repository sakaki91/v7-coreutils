#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// l - v1.2
// Copyright (C) by Sakaki, 2026.
// LICENSE: BSD 3-Clause License <https://opensource.org/license/bsd-3-clause>

void listDirectory(DIR *dir){
    struct dirent *entry;
    if (dir == NULL){
        perror("l");
        exit(EXIT_FAILURE);
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
    dir = (argc > 1) ? opendir(argv[1]) : opendir(".");
    listDirectory(dir);
    return 0;
}
