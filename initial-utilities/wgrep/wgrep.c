#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void grep(void *ptr, char *term)
{
    char *lineptr = NULL;
    size_t n = 0;
    while (getline(&lineptr, &n, ptr) != -1)
        if (strstr(lineptr, term) != NULL)
            printf("%s", lineptr);
    free(lineptr);
}

int main(int argc, char *argv[])
{
    // no search term specified
    if (argc < 2)
    {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    // no files specified
    if (argc < 3)
    {
        // read from stdin
        grep(stdin, argv[1]);
    }

    for (char **pargv = argv + 2; *pargv != argv[argc]; pargv++)
    {
        FILE *fp = fopen(*pargv, "r");
        if (fp == NULL)
        {
            printf("wgrep: cannot open file\n");
            exit(1);
        }
        grep(fp, argv[1]);
        fclose(fp);
    }
}