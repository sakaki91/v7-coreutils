#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char *argv[]){
    FILE *f;
    char *dir;
    int current_dir;
    char *file_open = "/home/sakaki/teste";
    if (argc < 2){
        char *user = getenv("HOME");
        current_dir = chdir(user);
        f = fopen(file_open, "w");
        fprintf(f, "te");
        fclose(f);
        printf("%d\n", current_dir);
    }
    return 0;
}
