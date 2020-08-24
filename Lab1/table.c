#include <stdio.h>

int main()
{

    int input;
    scanf("%d", &input);

    printf("\nN\t| N*N\n");
    printf("---------------\n");
    for (int i = 1; i <= input; i++)
    {
        printf("%d\t| %d\n", i, i * i);
    }
}