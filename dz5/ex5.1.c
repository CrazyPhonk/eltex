#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 256

int main(int argc, char *argv[]) {
    char login[MAX_LENGTH];
    char buf[MAX_LENGTH];
    char symb;
    char *line = NULL;
    char readed;
    size_t len = 0;
    printf("Login:\n");
    scanf("%s", login);
    FILE * fileFd;
    fileFd = fopen("/etc/passwd", "r");
    if (!fileFd){
        perror("Can not open the file\n");
        exit(-1);
    }
    while (fgets(buf, MAX_LENGTH, fileFd) != NULL) {
        if(strstr(buf, login) != 0)
        printf("%s", buf);
        }
}