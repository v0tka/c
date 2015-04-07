#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a = 2;
  int b = 2;
  int status;

  int pid_proceso = fork();

  if (pid_proceso == 0) {
    exit(a+b);
  } else {
    waitpid(pid_proceso,&status,0);
    printf("%d\n",WSTOPSIG(status));
  }


  return 0;
}