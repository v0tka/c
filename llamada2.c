#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {

  pid_t proceso = fork();

  if (proceso == 0) {
    execl("/bin/bash", "/bin/bash", "-c", "ls --color",NULL);
    perror("execl() failure!\n");
  }

  return 0;
}