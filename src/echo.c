#include <stdio.h>

// echo - v1.0
// Copyright (C) by Sakaki, 2026.
// LICENSE: BSD 3-Clause License <https://opensource.org/license/bsd-3-clause>

int main(int argc, char *argv[]){
    for(int i = 1; i < argc; i++){
        printf("%s ", argv[i]);
    } printf("\n");
    return 0;
}
