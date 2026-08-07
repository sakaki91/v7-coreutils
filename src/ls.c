#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>

// ls - v1.6
// Copyright (C) by Sakaki, 2026.
// LICENSE: BSD 3-Clause License <https://opensource.org/license/bsd-3-clause>

int main(int argc, char *argv[]){
    DIR *dir;
    struct dirent *entry;
    bool occult = false;
    if (argc < 2){
        dir = opendir(".");
    } else {
        if(strcmp(argv[1], "-a") == 0){
            occult = true;
            if (argc < 3){
                dir = opendir(".");
            } else {
                dir = opendir(argv[2]);
            }
        } else {
            dir = opendir(argv[1]);
        }
    }
    if(dir == NULL){
        perror("ls");
        exit(EXIT_FAILURE);
    }
    while((entry = readdir (dir)) != NULL){
        if (occult != true){
            if (entry->d_name[0] == '.'){
                continue;
            }
        }
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
    return 0;
}
