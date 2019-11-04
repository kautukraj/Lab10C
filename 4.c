#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp1, *fp2, *fp3; // creating file pointers
    char ch;
    fp1 = fopen("file1.txt", "r"); // opening in read only mode
    fp2 = fopen("file2.txt", "r");
    fp3 = fopen("filecat.txt", "w"); // opening the file in write mode

    if (fp1 == NULL || fp2 == NULL || fp3 == NULL) // fopen() returns NULL if unable to open any file
    {
        printf("Cannot open file");
        exit(1); // exit the program execution
    }

    while (1) // infinite loop
    {
        ch = fgetc(fp1); // retreive character from a file
        if (ch == EOF) // EOF = end of file
            break;
        fputc(ch, fp3); // insert character into a file
    }


    while (1)
    {
        ch = fgetc(fp2);
        if (ch == EOF)
            break;
        fputc(ch, fp3);
    }

    fclose(fp1);
    fclose(fp2); // closing the files
    fclose(fp3);
    return 0;
}
