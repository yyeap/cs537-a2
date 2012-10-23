#include <stdio.h>
#include "q.h"

#define ARRAY_SIZE 64

void reader(sq *q1){
    FILE *in;
    char inputString[ARRAY_SIZE];
    char c;
    int count, errFlag = 0;

    while (!feof(in)){
        printf("Enter string: ");
        in = stdin;
        count = 0;
        errFlag = 0;

        c = fgetc(in);
        /* if there is an error in reading stdin, handle it */
        if (!ferror(in)){
            printf("ERROR: Failed to read stdin.");
            continue;
        }

        while ('\n' != c){
            /* if there is a null byte, discard input */
            if ('\0' == c){
                printf("ERROR: Null byte found. Discard input");
                errFlag = 1; /* set error flag to true */
                break;
            }
            /* discard further input if string size > 63 */
            else if (count > 62){
                ;
            }
            /* write current character to array */
            else {
                inputString[count++] = c;
                /* get the next input character */
                c = fgetc(in);
                /* validate next input character */
                if(!ferror(in)){
                    printf("ERROR: Failed to read stdin.");
                    errFlag = 1;
                    break;
                }
            }
        }
        /* only add valid input to the queue */
        if (!errFlag){
            /* null terminate inputString */
            inputString[count] = '\0';
            /* send string to queue */
            sq_enq(q1, inputString);
        }
    }
    fclose(in);
}