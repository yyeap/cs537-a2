#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main ()
{
    char inputString[] = "Hello World";
    char *input = inputString;

    while (*input != '\0'){
        *input = toupper(*input);
        input = input + (sizeof(char));
    }
    printf("%s", inputString);
    return 0;
}
