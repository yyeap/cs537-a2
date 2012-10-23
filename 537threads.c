#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "reader.h"
#include "munch1.h"
#include "munch2.h"
#include "writer.h"

#define THREADS 4
#define QUEUES 3

int main(int argc, char **argv)
{
  pthread_t thr[THREADS];
  int i = 0;

  /* create synchronized queues */
  while(i < QUEUES)
  {
    sq q[i] = (sq*)malloc(sizeof(sq));
    i++;
  }

  /* create threads */
  if(pthread_create(thr[0], NULL, &reader, q))
  {
    printf("Could not create reader\n");
    return -1;
  }

  if(pthread_create(thr[1], NULL, &munch1, q))
  {
    printf("Could not create munch1\n");
    return -1;
  }

  if(pthread_create(thr[2], NULL, &munch2, q))
  {
    printf("Could not create munch2\n");
    return -1;
  }

  if(pthread_create(thr[3], NULL, &writer, q))
  {
    printf("Could not create writer\n");
    return -1;
  }

  /* join threads */
  if(pthread_join(thr[0], NULL))
  {
    printf("Could not join reader\n");
    return -1;
  }

  if(pthread_join(thr[1], NULL))
  {
    printf("Could not join munch1\n");
    return -1;
  }
  
  if(pthread_join(thr[2], NULL))
  {
    printf("Could not join munch2\n");
    return -1;
  }
  
  if(pthread_join(thr[3], NULL))
  {
    printf("Could not join writer\n");
    return -1;
  }

  /* destroy synchronized queues */
  i = 0;
  while(i < QUEUES)
  {
    sq_destroy(q[i]);
    free(q[i]);
    i--;
  }

  /* exit */
  pthread_exit(NULL);
  return 0;
}
