#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/wait.h> // for wait()

int input(char *s, int length);

struct name
{
	char **tok;
	int count;
};

#define MAXTOKS 100

enum status_value
{
	SUCCESS = 1,
	EOF_OR_ERROR = 0,
	TOO_MANY_TOKENS = 0,
};

int getFirstWhiteSpaceIdx(char chars[])
{
	int index = 0;
	while (chars[index])
	{
		if (isspace(chars[index]))
		{
			return index;
		}
		index++;
	}
	return index;
}

int read_name(struct name *input_name)
{
	char buffer[100];
	char *tok[100];

	// get input
	printf("Type something: ");
	fgets(buffer, 100, stdin);

	char empty_buffer[100];
	tok[0] = empty_buffer;

	int firstWhiteSpaceIdx = getFirstWhiteSpaceIdx(buffer);

	int bufferIdx = 0;
	int count = 0;

	while (buffer[bufferIdx])
	{
		tok[0][bufferIdx] = buffer[bufferIdx];
		count++;

		if (count > MAXTOKS)
		{
			return TOO_MANY_TOKENS;
		}

		bufferIdx++;
	}

	input_name->tok = tok;
	input_name->count = count;

	return SUCCESS;
}

int main()
{
	struct name input_name;

	if (read_name(&input_name))
	{
		// printf("%s\n", input_name.tok[0]);
	}
	else
	{
		printf("Error in input.");
	}

	if (fork() == 0)
	{
		printf("Child running\n");
		char *commands[] = {"ls", NULL, NULL, NULL};
		execve("/bin/ls", commands, NULL);
	}
	else
	{
		wait(NULL);
		printf("Parent running\n");
	}

	return (0);
}
