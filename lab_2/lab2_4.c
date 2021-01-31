#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main() {
  int pid = fork();
  if(pid < 0)
  {
    printf("fork failed");
    exit(1);
  } else if(pid == 0) {
    execlp("whoami","ls",NULL);
    exit(0);
  } else {
    printf("\n Process id is -%d\n", getpid());
    wait(NULL);
    exit(0);
  }
  return 0;
}
