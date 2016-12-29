#include <stdio.h>
#include <pthread.h>
void *foo(void *arg)
{
  printf("%d", "I am foo");
  pthread_exit();
}
int main()
{
  pthread_t tid;
  pthread_create(&tid, NULL, foo, NULL);
  return 0;
}
