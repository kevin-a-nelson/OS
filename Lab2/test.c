#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct name
{
    char **tok;
};

size_t firstWhiteSpaceIndex(const char *s)
{
    size_t size = 0;

    while (*s++)
    {
        if (isspace(*s))
        {
            break;
        }
        ++size;
    }

    return size;
}

int main()
{
    struct name input_name;

    char **input_tok;

    size_t buff_size = 32;
    char *buffer;

    getline(&buffer, &buff_size, stdin);

    int input_size = firstWhiteSpaceIndex(buffer);

    printf("First white space char: %d\n", input_size);

    input_tok[0] = buffer;

    for (int i = 0; i < input_size; i++)
    {
        printf("%c", buffer[i]);
        // input_tok[0][0] = buffer[0];
    }

    input_name.tok = input_tok;

    printf("%c\n", input_name.tok[0][0]);
    printf("%s\n", input_name.tok[0]);
}