#include <stdio.h>
#include <ctype.h>
#include <string.h>

void munch2 ()
{
    char inputString[] = "Hello World";
    char *input = inputString;

    while (*input != '\0'){
        *input = toupper(*input);
        input = input + (sizeof(char));
    }
    printf("%s", inputString);
}
