#include <string.h>
#include <stdio.h>
#include <strings.h>
#include "munch1.h"
#include "synchq.h"

void *munch1 (void* q)
{
    printf("start munch1\n");
    sq** queues = (sq**)q;

    /*get string from q0 */
    char *str, *curr;

    while(!sq_isDone(queues[0])) /* while not EOF */
    {
        if (NULL == (str = sq_deq(queues[0])))
        {
            printf("ERROR: Failed to get string from q1.");
            return NULL;
        }
        curr = index(str, ' ');
        printf("before update space to *\n");
        while (NULL != curr)
        {
            *curr = '*';
            printf("update * success\n");
            curr = index(str, ' ');
        }
        printf("before munch1 enq\n");
        /* put string on q1 */
        sq_enq(queues[1], str);
        printf("after munch1 enq\n");
    }
    sq_done(queues[1]); /* set done flag on the next queue */
    return NULL;
}

