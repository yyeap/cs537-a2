#include <stdio.h>
#include <stdlib.h>
#include "reader.h"
#include "synchq.h"

#define ARRAY_SIZE 64

void * reader(void *q)
{
  printf("start reader\n");
  sq **queues = (sq**)q; /* cast to array of queues */
  FILE *in;
  char *input, c;
  int count, nullErr, atEOF, lineComplete;
  /*
    loop for input one line at a time
    loop inside this loop for each character individually
  */
  printf("before while loop\n");
  while (!feof(in)  && !ferror(in))
  {
    /*
      create array to hold input
      create flags and counters
    */
    printf("before stdin\n");
    in = stdin;
    printf("after stdin\n");
    count = 0;
    nullErr = 0;
    atEOF = 0;
    lineComplete = 0;

    printf("before malloc input\n");
    if(NULL == (input = (char*)malloc(ARRAY_SIZE * sizeof(char))))
    {
      printf("ERROR: Failure to allocate input buffer.\n");
      return NULL;
    }
printf("after malloc input\n");
    /*loop for character*/
    while (!lineComplete && !nullErr)
    {
      c = fgetc(in);
      if (EOF == c)
      {
        lineComplete = 1;
        /*SOMETHING ELSE*/
      }
      else if ('\0' == c)
      {
        nullErr = 1;
      }
      else if ('\n' == c)
      {
        lineComplete = 1;
      }
      else if(count < ARRAY_SIZE)
      {printf("before adding c to input\n");
        input[count] = c;
        printf("after adding c to input\n");
        count++;
      }
    }
    if(!nullErr)
    {
      input[count] = '\0';
      printf("before reader enq\n");
      sq_enq(queues[0], input);
      printf("after read enq\n");
    }
  }
  sq_done(queues[0]);
  fclose(in);
  exit(1);
}
