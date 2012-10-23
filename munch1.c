#include <string.h>
#include <stdio.h>
#include <strings.h>
#include "q.h"

void * munch1 (sq** q){
    /*get string from q0 */
    char *str, *curr;
    str = sq_deq(q[0]);

    if (NULL == str){
        printf("ERROR: Failed to get string from q1.");
        return;
    }
    curr = index(str, ' ');

    while (NULL != curr){
        *curr = '*';
        curr = index(str, ' ');
    }

    /* put string on q1 */
    sq_enq(q[1], str);
    return NULL;
}

