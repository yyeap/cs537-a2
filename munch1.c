#include <string.h>
#include <stdio.h>
#include <strings.h>
#include "munch1.h"

void * munch1 (void* q){
    sq** queues = (sq**)q;

    /*get string from q0 */
    char *str, *curr;
    str = sq_deq(queues[0]);

    if (NULL == str){
        printf("ERROR: Failed to get string from q1.");
        return NULL;
    }
    curr = index(str, ' ');

    while (NULL != curr){
        *curr = '*';
        curr = index(str, ' ');
    }

    /* put string on q1 */
    sq_enq(queues[1], str);
    return NULL;
}

