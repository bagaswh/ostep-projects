#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++)
    {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("wzip: cannot open file\n");
            exit(1);
        }

        int bytes = 0;
        do
        {
            int c;
            fread(&c, 4, 1, fp);
            char ch;
            bytes = fread(&ch, 1, 1, fp);
            if (bytes > 0)
                for (int i = 0; i < c; i++)
                    printf("%c", ch);
        } while (bytes > 0);
    }
}