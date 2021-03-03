/*
** Q6.c -- a smartest pipe example using cat /etc/group|sort|cut -f3 -d:
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  int pfds[2]; // Size 2 arrays denoting the pipe inputs and outputs
  int sndpfds[2];

  pipe(pfds);

  switch (fork()) {
    case -1: // Error check
    perror("Fork");
    exit(1);

    case 0:
    pipe(sndpfds); // If fork is in its child process, pipe 2nd array

    switch (fork()) {
      case -1: // Error check
      perror("Fork");
      exit(2);

      case 0: // child of the next fork is cat, start switching standard input and output
      dup2(sndpfds[1], STDOUT_FILENO); // make stdout same as sndpfds[1]
      close(sndpfds[0]); // close stdin
      close(sndpfds[1]); // close stdout
      execlp("/usr/bin/cat", "/usr/bin/cat", "/etc/group", NULL); // place cat command in new out pipe
      exit(3);

      default: // check parent of current fork which is sort command
      dup2(sndpfds[0], STDIN_FILENO); // make stdin same as sndpfds[0]
      dup2(pfds[1], STDOUT_FILENO); // make stdout same as pfds[1]
      close(sndpfds[0]); // close stdin
      close(sndpfds[1]); // close stdout
      execlp("/usr/bin/sort", "/usr/bin/sort", NULL); // place sort command in between out of pipe1 and in of pipe2
      exit(3);
    }
    default: // if all other child processes are checked, check the final parent process, which is cut
    dup2(pfds[0], STDIN_FILENO); // make stdin same as pfds[0]
    close(pfds[0]);
    close(pfds[1]);
    execlp("/usr/bin/cut", "/usr/bin/cut", "-f3", "-d:", NULL); // final pipe input would be cut, as pipes are built in reverse due to stack structure
    exit(5);
  }
  return 0;
}
