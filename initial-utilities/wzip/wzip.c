#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void write(int c, char ch)
{
    fwrite(&c, sizeof(int), 1, stdout);
    fwrite(&ch, 1, sizeof(ch), stdout);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    char prev = -1;
    char ch;
    int count = 0;
    for (int i = 1; i < argc; i++)
    {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("wzip: cannot open file\n");
            exit(1);
        }

        while ((ch = fgetc(fp)) != EOF)
        {
            if (prev == -1 || ch == prev)
                count++;
            else
            {
                write(count, prev);
                count = 1;
            }
            prev = ch;
        }
        fclose(fp);
    }

    if (count > 0)
        write(count, prev);
}