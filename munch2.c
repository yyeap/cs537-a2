#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "munch2.h"

void * munch2 (sq** q)
{
    /* get string from the queue */
    char *inputString, *curr;
    inputString = sq_deq(q[1]);

    if (NULL == inputString){
        printf("ERROR: Input is empty.");
        return;
    }

    curr = inputString;

    while (*curr != '\0'){
        *curr = toupper(*curr);
        curr = curr + (sizeof(char));
    }
    /* push modified string to the queue */
    sq_enq(q[2], inputString);

    return NULL;
}
