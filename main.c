#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STRLEN 81
#define BUFSIZE 4096
char *s_gets(char *fName, int length);
void append(FILE* dest, FILE* source);

int main()
{
    FILE *sourceFile;
    FILE *destinationFile;

    char sourceFileN[STRLEN];
    char destinationFileN[STRLEN];

    printf("Enter destination file name: ");
    s_gets(destinationFileN, STRLEN);

    //ALways point to the end of the file to add more content
    if((destinationFile = fopen(destinationFileN, "a+")) == NULL){
        fprintf(stderr,"Destination file failed to open");
        exit(EXIT_FAILURE);
    }

    if(setvbuf(destinationFile, NULL, _IOFBF, BUFSIZE) != 0){
        fprintf(stderr,"Buffer output creation failed");
        exit(EXIT_FAILURE);
    }



    return 0;
}

char *s_gets(char *fName, int length)
{
    char * ptr;
    char * newLinePtr;
    ptr = fgets(fName, length, stdin);
    if(ptr != NULL){
        newLinePtr = strchr(fName, '\n');
        if(newLinePtr != NULL){
            *newLinePtr = '\0';
        }
        else{
            while(getchar() != '\n'){
                continue;
            }
        }
    }

    return ptr;
}

void append(FILE* dest, FILE* source){
    //Create a buffer here to transfer the text
    char tempBuff[BUFSIZE];
    size_t byte;
    while(byte = fread(tempBuff, tempBuff[0], BUFSIZE, source) > 0){
        fwrite(tempBuff, sizeof(tempBuff[0]), BUFSIZE, dest);
    }
}
