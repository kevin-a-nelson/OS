
#include <stdio.h>
#include <stdlib.h> /* for exit() */

int main(int argc, char **argv, char **envp)
{

	int i = argc; /* index into array argv[] */ 

	while (i--) {
		printf("%s ", argv[i]);
	}

	printf("\n");

	exit(argc);  /* normal exit status would be 0 */
}

// type this in the terminal to run this file

// gcc reverse.c && ./a.out a b c d e
