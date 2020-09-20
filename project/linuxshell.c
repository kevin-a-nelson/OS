#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void getAndRunCommand()
{
    if (fork() == 0)
    {
        char userInput[100];
        char userInputWords[10][10];
        int i, lengthOfWord, numberOfWords;

        printf(">> ");

        // Get input until "\n" ( where the user hits enter )
        scanf("%[^\n]%*c", userInput);

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

        char* pathToBin = "/bin/";
        char* firstCommand = commands[0];
        char* pathToCommand = concat(pathToBin, firstCommand);

        execve(pathToCommand, commands, NULL);
    }
    else
    {
        wait(NULL);
    }
}

int main(void)
{
    printf("\n\nWelcome to nelsonOS!\n");
    printf("---------------------------------------\n");
    while(1) {
        getAndRunCommand();
    }
}
