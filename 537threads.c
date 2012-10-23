#include <pthread.h>
#include <stdio.h>



int main(int argc, char **argv)
{
  pthread_t thr;
  if(pthread_create(&thr, NULL, &reader, NULL))
  {
      printf("Could not create reader\n");
      return -1;
  }
  pthread_t thr;
  if(pthread_create(&thr, NULL, &munch1, NULL))
  {
      printf("Could not create munch1\n");
      return -1;
  }
  pthread_t thr;
  if(pthread_create(&thr, NULL, &munch2, NULL))
  {
      printf("Could not create munch2\n");
      return -1;
  }
  pthread_t thr;
  if(pthread_create(&thr, NULL, &writer, NULL))
  {
      printf("Could not create writer\n");
      return -1;
  }

}
