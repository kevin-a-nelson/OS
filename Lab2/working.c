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

int read_name(struct name *input_name)
{
    char **input_tok;
    size_t buff_size = 32;
    char *buffer;

    buffer = (char *)malloc(buff_size * sizeof(char));
    getline(&buffer, &buff_size, stdin);

    input_tok[0] = buffer;

    input_name->tok = input_tok;

    printf("%s \n", input_name->tok[0]);

    enum status_value status = NORMAL;

    if (input_name->tok == NULL)
    {
        status = EOF_OR_ERROR;
        return EOF_OR_ERROR;
    }
    else
    {
        return NORMAL;
    }
}

int main()
{
    struct name *input_name;

    int output = read_name(input_name);

    if (output == 0)
    {
        printf("Error in input. \n");
    }
    else if (output == 1)
    {
        printf("Input successful. \n");
    }

    return (0);
}