#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "reader.h"
#include "munch1.h"
#include "munch2.h"
#include "writer.h"

#define THREADS 4
#define BUFFERS 3

int main(int argc, char **argv)
{
  pthread_t thr[THREADS];

  if(pthread_create(&thr[0], NULL, &reader, NULL))
  {
      printf("Could not create reader\n");
      return -1;
  }

  if(pthread_create(&thr[1], NULL, &munch1, NULL))
  {
      printf("Could not create munch1\n");
      return -1;
  }

  if(pthread_create(&thr[2], NULL, &munch2, NULL))
  {
      printf("Could not create munch2\n");
      return -1;
  }

  if(pthread_create(&thr[3], NULL, &writer, NULL))
  {
      printf("Could not create writer\n");
      return -1;
  }
  pthread_join(thr[3]);
  pthread_exit(NULL);
  return 0;
}
