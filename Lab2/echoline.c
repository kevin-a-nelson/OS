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
	NORMAL,
	EOF_OR_ERROR
};

int read_name(struct name *input_name)
{
	size_t buff_size = 32;
	size_t chars;
	char c = 'a';
	char *buffer;
	// enum status_value status = NORMAL;
	// printf("Input a line: ");
	// chars = getline(&buffer, &buff_size, stdin);
	input_name->tok[0] = buffer;
	// printf("You input: %s", &input_name->tok[0]);
	// printf("You input %zu chars. \n", chars);

	if (input_name->tok == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	struct name *input_name;

	if (read_name(input_name))
	{
		printf("Error in input.");
	}
	else
	{
		printf("You typed: %s.\n", input_name->tok[0]);
	}

	return (0);
}