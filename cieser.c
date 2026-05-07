#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE* input_fp, * output_fp;
    char filename[FILENAME_MAX + 1], enc_filename[FILENAME_MAX + 4 + 1];
    int ch, shift;

    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }
    strcpy(filename, argv[1]);
    if (filename[strlen(filename) - 1] == '\n')
        filename[strlen(filename) - 1] = '\0';

    if ((input_fp = fopen(filename, "r")) == NULL) {
        printf("Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    strcpy(enc_filename, filename);
    strcat(enc_filename, ".enc");
    if ((output_fp = fopen(enc_filename, "w")) == NULL) {
        printf("Can't open %s\n", enc_filename);
        fclose(input_fp);
        exit(EXIT_FAILURE);
    }

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    while ((ch = getc(input_fp)) != EOF) {
        if ('A' <= ch && ch <= 'Z')
            ch = ((ch - 'A') + shift) % 26 + 'A';
        else if ('a' <= ch && ch <= 'z')
            ch = ((ch - 'a') + shift) % 26 + 'a';
        putc(ch, output_fp);
    }

    fclose(input_fp);
    fclose(output_fp);
    return 0;
}