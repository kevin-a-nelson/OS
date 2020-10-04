/* Example of FILE I/0
   From www.cplusplus.com/reference/clibrary/cstdio/FILE/
   Modified to use getline(), 10/2015*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define COLUMNS 128 
#define ROWS 10 

int main()
{
    char fileToReadContents[ROWS][COLUMNS];

	char fileToReadName[20];
    FILE *fileToRead = NULL; 

    char fileToWriteName[20];
    FILE * fileToWrite;

    int lineNumber = 0;
    int numberOfLines = 0;

    printf("\n\n Read the file and store the lines into an array :\n");
	printf("------------------------------------------------------\n"); 
	printf(" Input the filename to copy: ");
	scanf("%s",fileToReadName);	
    printf(" Input the file name to copy to: ");
    scanf("%s", fileToWriteName);

    fileToRead = fopen(fileToReadName, "r");
    while(fgets(fileToReadContents[lineNumber], COLUMNS, fileToRead)) 
	{
        lineNumber++;
    }

    numberOfLines = lineNumber;

	// printf("The contents of %s, has been copyied to %s",fileToReadName, fileToWrite);    
    // for(lineNumber = 0; lineNumber < numberOfLines; ++lineNumber)
    // {
    //     printf("%s", fileToReadContents[lineNumber]);
    // }
    // printf("\n");

   lineNumber = 0;
   /* open the file for writing*/
   fileToWrite = fopen (fileToWriteName,"w");
 
   /* write 10 lines of text into the file stream*/
   for(lineNumber = 0; lineNumber < 10;lineNumber++){
       fprintf(fileToWrite, fileToReadContents[lineNumber],lineNumber + 1);
   }
 
   printf("The contents of %s, has been copyied to %s\n",fileToReadName, fileToWriteName);    
   /* close the file*/  
   fclose (fileToWrite);

    return 0;
}
