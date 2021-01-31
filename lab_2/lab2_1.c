#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
  printf("Process ID is: %d\n", getpid());
  printf("Parent process ID is: %d\nNow sleeping\n", getppid());
  sleep(60); /* sleep for 60 seconds */
  printf("I am awake.\n");
  return 0;
}
