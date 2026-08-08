#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/utsname.h>

// uname - v2.1
// Copyright (C) by Sakaki, 2026.
// LICENSE: BSD 3-Clause License <https://opensource.org/license/bsd-3-clause>

int main(int argc, char *argv[]){
    struct utsname buffer;
    int args;
    bool s = false;
    bool r = false;
    bool v = false;
    bool n = false;
    bool m = false;
    if(uname(&buffer) != 0){
        perror("uname");
    }
    if (argc < 2){
        printf("%s\n", buffer.sysname);
    } else {
        while ((args = getopt(argc, argv, "hsrvnm")) != -1){
            if (args == 'h'){
                fprintf(stdout, "\033[4moperations:\033[0m\n"
                                "-h   show this message.\n"
                                "-s   print the kernel name.\n"
                                "-r   print the kernel release.\n"
                                "-v   print the kernel version.\n"
                                "-n   print the hostname.\n"
                                "-m   print the machine hardware name.\n\n"
                                "usage: uname <operation>\n");
                exit(EXIT_SUCCESS);
            } else {
                if (args == 's'){
                    s = true;
                }
                if (args == 'r'){
                    r = true;
                }
                if (args == 'v'){
                    v = true;
                }
                if (args == 'n'){
                    n = true;
                }
                if (args == 'm'){
                    m = true;
                }
            }
        }
        char *isa;
        if (isatty(1)){
            isa = "%s "; 
        } else {
            isa = "%s";
        }
        if (s == true){
            printf(isa, buffer.sysname);
        }
        if (r == true){
            printf(isa, buffer.release);
        }
        if (v == true){
            printf(isa, buffer.version);
        }
        if (n == true){
            printf(isa, buffer.nodename);
        } 
        if (m == true){
            printf(isa, buffer.machine);
        } 
        printf("\n");
    }
    return 0;
}
