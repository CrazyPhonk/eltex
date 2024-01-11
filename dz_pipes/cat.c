#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
            int c;
    if (argc == 2) {
        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("Error opening file");
            return 1;
        }
        while ((c = fgetc(file)) != EOF) {
            putchar(c);
        }

        fclose(file);
        } 
        else if (argc == 3 && strcmp(argv[1], ">") == 0) {
        FILE *file = fopen(argv[2], "w");
        if (file == NULL) {
            perror("Error opening file");
            return 1;
        }

        while ((c = getchar()) != EOF) {
            fputc(c, file);
        }
        fclose(file);
    } else {
        printf("Stdin");
    }

    return 0;
}