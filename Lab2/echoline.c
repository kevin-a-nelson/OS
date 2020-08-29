#include <stdio.h>
#include <stdlib.h>

int input(char *s, int length);

struct name
{
	char **tok;
	int count;
};

#define MAXTOKS char[size_of(name->tok)];

enum status_value
{
	NORMAL = 1,
	EOF_OR_ERROR = 0
};

int read_name(struct name input_name)
{

	char **input_tok;

	size_t buff_size = 32;
	char *buffer;

	getline(&buffer, &buff_size, stdin);

	input_tok[0] = buffer;

	input_name.tok = input_tok;

	printf("%s\n", input_name.tok[0]);

	if (input_name.tok[0] == NULL)
	{
		return NORMAL;
	}
	else
	{
		return EOF_OR_ERROR;
	}
}

int main()
{
	struct name input_name;

	if (read_name(input_name))
	{
		printf("Error in input.");
	}
	else
	{
		// printf("You typed: %s.\n", input_name.tok[0]);
	}

	return (0);
}