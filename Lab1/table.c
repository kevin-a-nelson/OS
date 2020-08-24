#include <stdio.h>

int main()
{

	int input;

	printf("Enter a Interger: ");
	scanf("%d", &input);

	printf("\nN\t| N*N\n");
	printf("---------------\n");
	for (int i = 1; i <= input; i++)
	{
		printf("%d\t| %d\n", i, i * i);
	}
}

// Type this in the terminal to run this file 

// gcc table.c && ./a.out
