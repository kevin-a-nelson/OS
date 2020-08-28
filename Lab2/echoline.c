#include <stdio.h>
#include <stdlib.h>

int input(char *s,int length);

int main()
{
	char *buffer;
	size_t bufsize = 32;
	size_t chars;

	if( buffer == NULL)
	{
	exit(1);
	}

	printf("Enter a sentence: ");
	chars = getline(&buffer,&bufsize,stdin);
	printf("You entered: %s",buffer);
	printf("Length: %zu\n", chars);

	return(0);
}
