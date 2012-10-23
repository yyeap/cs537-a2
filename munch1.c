#include <string.h>
#include <stdio.h>
#include <strings.h>

void munch1 ()
{
    char str[] = "he ef efwe f";
    char *curr = index(str, ' ');

    while (NULL != curr){
        *curr = '*';
        curr = index(str, ' ');
    }
    printf("%s", str);
    return;
}

