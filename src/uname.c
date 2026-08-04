#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>

// uname - v1.0
// Copyright (C) by Sakaki, 2026.
// LICENSE: BSD 3-Clause License <https://opensource.org/license/bsd-3-clause>

int main(int argc, char *argv[]){
    struct utsname buffer;
    if(uname(&buffer) != 0){
        perror("uname");
    }
    if (argc < 2){
        printf("%s %s\n", buffer.sysname, buffer.release);
    } else {
        if (strcmp(argv[1], "-v") == 0){
            printf("%s %s %s\n", buffer.sysname, buffer.release, buffer.version);
        } else if (strcmp(argv[1], "-h") == 0){
            fprintf(stdout, "\033[4muname\033[0m\n"
                    "-h    show this message.\n"
                    "-v    show kernel version.\n"
                   );
        } else {
            fprintf(stderr, "error, type -h to see the options.\n");
            exit(EXIT_FAILURE);
        }
    }   
}
