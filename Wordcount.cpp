#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c|-w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *filename = argv[2];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int charCount = 0;
    int wordCount = 0;
    int c;
    int inWord = 0;

    while ((c = fgetc(file)) != EOF) {
        charCount++;

        if (isspace(c)) {
            inWord = 0;
        } else {
            if (!inWord) {
                wordCount++;
                inWord = 1;
            }
        }
    }

    fclose(file);

    if (strcmp(argv[1], "-c") == 0) {
        printf("×Ö·ûÊý£º%d\n", charCount);
    } else if (strcmp(argv[1], "-w") == 0) {
        printf("µ¥´ÊÊý£º%d\n", wordCount);
    } else {
        printf("Invalid parameter. Use -c or -w.\n");
    }

    return 0;
}
