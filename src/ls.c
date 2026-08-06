#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

// ls - v1.5
// Copyright (C) by Sakaki, 2026.
// LICENSE: BSD 3-Clause License <https://opensource.org/license/bsd-3-clause>

int main(int argc, char *argv[]){
    DIR *dir; struct dirent *entry;
    dir = (argc < 2) ? opendir(".") : opendir(argv[1]);
    if(dir == NULL){
        perror("ls");
        exit(EXIT_FAILURE);
    }
    while((entry = readdir (dir)) != NULL){
        if (entry->d_name[0] == '.'){
            continue;
         }
         printf("%s\n", entry->d_name);
    }
    closedir(dir);
    return 0;
}
