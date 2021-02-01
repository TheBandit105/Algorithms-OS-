#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main (){
  for (int counter = 0; counter < 10; counter++){
    printf("\nparent %d process: counter = %d", getppid(), counter);
    printf("\nchild %d process: counter = %d", getpid(), counter);
    printf("\nchild %d process: counter = %d\n", getpid() + 1, counter);
    sleep(1);
  }
  return 0;
}
