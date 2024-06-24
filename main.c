#include <stdio.h>
#define STRLEN 81
char *s_gets(char *, int);

int main()
{
    FILE *sourceFile;
    FILE *destinationFile;

    char sourceFileN[STRLEN];
    char destinationFileN[STRLEN];

    printf("Enter destination file name: ");
    s_gets(destinationFileN, STRLEN);

    return 0;
}