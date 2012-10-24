#include <stdio.h>
#include <stdlib.h>
#include "reader.h"

#define ARRAY_SIZE 64

void * reader(void *q){
  sq **queues = (sq**)q; /* cast to array of queues */
  FILE *in;
  char *input, c;
  int count, nullErr, atEOF, lineComplete;
  /*
    loop for input one line at a time
    loop inside this loop for each character individually
  */
  
  while (!feof(in)  && !ferror(in)) 
  {
    /*
      create array to hold input
      create flags and counters
    */
    in = stdin;
    count = 0;
    nullErr = 0;
    atEOF = 0;
    lineComplete = 0;

    if(NULL == (input = (char*)malloc(ARRAY_SIZE * sizeof(char))))
    {
      printf("ERROR: Failure to allocate input buffer.\n");
    }
    
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
      } else if(count < ARRAY_SIZE) {
        input[count] = c;
        count++;
      }
    }
    if(!nullErr)
    {
      input[count] = '\0';
      sq_enq(queues[0], input);
    }
  }
  fclose(in);
  exit(1);
}
