#include <stdio.h>

// clear - v1.1
// Copyright (C) by Sakaki, 2026.
// LICENSE: BSD 3-Clause License <https://opensource.org/license/bsd-3-clause>

int main(){
    printf("\033[2J\033[H\033[3J");
    return 0;
}
