#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(){
  fork();
  fork();
  printf("Process ID is: %d\n", getpid());
  printf("Parent Process ID is %d\n", getppid());
  sleep(2);
  return 0;
}
