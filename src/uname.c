#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/utsname.h>

// uname - v2.0
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
        if (strcmp(argv[1], "-h") == 0){
            fprintf(stdout, "\033[4moperations:\033[0m\n"
                            "-h   show this message.\n"
                            "-s   print the kernel name.\n"
                            "-r   print the kernel release.\n"
                            "-v   print the kernel version.\n"
                            "-n   print the hostname.\n"
                            "-m   print the machine hardware name.\n\n"
                            "usage: uname <operation>\n");
            exit(EXIT_SUCCESS);
        }
        while ((args = getopt(argc, argv, "srvnm")) != -1){
            switch (args){
                case 's':
                    s = true;
                    break;
                case 'r':
                    r = true;
                    break;
                case 'v':
                    v = true;
                    break;
                case 'n':
                    n = true;
                    break;
                case 'm':
                    m = true;
                    break;
            }
        }
        if (s == true){
            printf("%s", buffer.sysname);
        }
        if (r == true){
            printf("%s", buffer.release);
        }
        if (v == true){
            printf("%s", buffer.version);
        }
        if (n == true){
            printf("%s", buffer.nodename);
        } 
        if (m == true){
            printf("%s", buffer.machine);
        } printf ("\n");
    }
}
