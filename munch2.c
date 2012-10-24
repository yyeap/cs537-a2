#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "munch2.h"
#include "synchq.h"

void * munch2 (void * q)
{
    printf("start munch2\n");
    sq** queues = (sq**)q;
    /* get string from the queue */
    char *inputString, *curr;
    printf("before munch2 while\n");
    while(!sq_isDone(queues[1]))
    {
printf("got into munch2 while\n");
        if (NULL == (inputString = sq_deq(queues[1])))
        {
            printf("ERROR: Input is empty.");
            return NULL;
        }

        curr = inputString;

        while (*curr != '\0'){
	printf("before toupper\n");
            *curr = toupper(*curr);
printf("after toupper\n");
            printf("before increment curr pointer munch2\n");
            curr = curr + (sizeof(char));
            printf("increment pointer success\n");
        }
        /* push modified string to the queue */
printf("before munch2 enq\n");
        sq_enq(queues[2], inputString);
printf("after munch2 enq\n");
    }
    sq_done(queues[2]); /* set done flag on the next queue */
    return NULL;
}
