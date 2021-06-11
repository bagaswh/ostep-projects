#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        return 0;
    }

    for (char **pargv = argv + 1; *pargv != argv[argc]; pargv++)
    {
        char buffer[BUFFER_SIZE];
        FILE *fp = fopen(*pargv, "r");
        if (fp == NULL)
        {
            printf("wcat: cannot open file\n");
            exit(1);
        }

        while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
        {
            printf("%s", buffer);
        }
        fclose(fp);
    }
}