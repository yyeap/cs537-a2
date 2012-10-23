#include <string.h>
#include <stdio.h>
#include <strings.h>
#include "q.h"

void munch1 (sq *q1, sq *q2){
    /*get string from q1 */
    char *str, *curr;
    str = sq_deq(q1);

    if (NULL == str){
        printf("ERROR: Failed to get string from q1.");
        return;
    }
    curr = index(str, ' ');

    while (NULL != curr){
        *curr = '*';
        curr = index(str, ' ');
    }

    /* put string on q2 */
    sq_enq(q2, str);
    return;
}

