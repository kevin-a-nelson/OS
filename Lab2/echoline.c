#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int input(char *s, int length);

struct name
{
	char **tok;
	int count;
};

#define MAXTOKS char[size_of(name->tok)];

enum status_value
{
	SUCCESS = 1,
	EOF_OR_ERROR = 0
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

	for (int i = 0; i < firstWhiteSpaceIdx; i++)
	{
		tok[0][i] = buffer[i];
	}

	input_name->tok = tok;

	return SUCCESS;
}

int main()
{
	struct name input_name;

	if (read_name(&input_name))
	{
		printf("%s\n", input_name.tok[0]);
	}
	else
	{
		printf("Error in input.");
	}

	return (0);
}