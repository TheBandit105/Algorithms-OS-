#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main (){
// child processes initialised and forked at once.
  int kid1 = fork();
  int kid2 = fork();

// iteration of the process ids creation for 10 increments.
  for (int counter = 0; counter <= 10; counter++){
    if (kid1 == 0){
    printf("child %d process: counter = %d\n", getpid(), counter);
  } else if (kid2 == 0){
    printf("parent %d process: counter = %d\n", getppid(), counter);
  }
  // sleep(1) delays the printed results for 1 second each.
    sleep(1);
  }
  return 0;
}
