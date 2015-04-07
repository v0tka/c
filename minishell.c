#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define TRUE 1

int main(int argc, char const *argv[]) {
  char command[50];
  pid_t proceso;
  int status;

  while (TRUE) {
    proceso = fork();
    if (proceso == 0) {
      printf("$ ");
      scanf("%s", command);
      execl("/bin/bash", "bash", "-c",command, NULL);
      perror("execl() failure!\n");
      exit(0);
    } else {
      waitpid(proceso,&status,0);
    }

  }

  return 0;
}