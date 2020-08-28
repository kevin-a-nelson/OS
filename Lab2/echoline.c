/* example of struct in C. RAB 1/2001 */
#include <stdio.h>
struct name
{
	int count;
	char *input_name;
	int status;
};

int read_name(struct name *input_name)
{
	size_t bufsize = 32;
	size_t chars;

	printf("Enter a sentence: ");
	chars = getline(&input_name->input_name, &bufsize, stdin);

	if (input_name->input_name == NULL)
	{
		return 0;
	}

	input_name->status = 1;

	return 1;
}

/* main program */
int main()
{
	struct name input_name;

	if (!read_name(&input_name))
	{
		printf("Unable to read name successfully\n");
	}
	else
	{
		printf("You entered: %s\n", input_name.input_name);
	}

	return 0;
}