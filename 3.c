#include<stdio.h> 
#include<stdlib.h>

int main()  
{ 
    system("date > file1.txt"); // calling the UNIX command date and storing the console output
    system("sleep 5"); // delay the execution of the following statements by 5 seconds
    system("date > file2.txt");

    FILE *fp1,*fp2; char ch;
    fp1 = fopen("file1.txt","r"); // opening the file in read-only mode
    fp2 = fopen("file2.txt","r");
    
    while(1)
    {
      ch = fgetc(fp1);
      if(ch==EOF) // EOF = end of file
         break;
      printf("%c", ch);
   }

    while(1)
    {
      ch = fgetc(fp2);
      if(ch==EOF)
         break;
      printf("%c", ch);
   }
   
   fclose(fp1);
   fclose(fp2); // closing the files
   return 0;
}
