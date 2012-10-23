#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "q.h"

void munch2 (sq *q2, sq *q3)
{
    /* get string from the queue */
    char *inputString, *curr;
    inputString = sq_deq(q2);

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
    sq_enq(q3, inputString);
}
