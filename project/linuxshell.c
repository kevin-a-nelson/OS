#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

void getAndRunCommand()
{
    if (fork() == 0)
    {
        char userInput[100];
        char userInputWords[10][10];
        int i, lengthOfWord, numberOfWords;

        printf(">> ");
        fgets(userInput, sizeof userInput, stdin);

        lengthOfWord = 0;
        numberOfWords = 0;
        for (i = 0; i <= (strlen(userInput)); i++)
        {
            // if space or NULL found, assign NULL into newString[ctr]
            if (userInput[i] == ' ' || userInput[i] == '\0')
            {
                userInputWords[numberOfWords][lengthOfWord] = '\0';
                numberOfWords++;  //for next word
                lengthOfWord = 0; //for next word, init index to 0
            }
            else
            {
                userInputWords[numberOfWords][lengthOfWord] = userInput[i];
                lengthOfWord++;
            }
        }

        char *commands[] = {NULL, NULL, NULL, NULL};
        for (i = 0; i < numberOfWords; i++)
        {
            commands[i] = userInputWords[i];
        }

        execve("/bin/ls", commands, NULL);
    }
    else
    {
        wait(NULL);
    }
}

int main(void)
{
    printf("\n\n Welcome to nelsonOS!\n");
    printf("---------------------------------------\n");
    while(1) {
        getAndRunCommand();
    }
}
