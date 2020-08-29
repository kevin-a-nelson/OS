#include <stdio.h>
#include <stdlib.h>

struct name
{
    char **tok;
};

int main()
{

    struct name input_name;

    char **input_tok;

    size_t buff_size = 32;
    char *buffer;

    getline(&buffer, &buff_size, stdin);

    input_tok[0] = buffer;

    input_name.tok = input_tok;

    printf("%s\n", input_name.tok[0]);
}