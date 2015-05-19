#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int descendencia = 1;
  pid_t pid;

  pid = fork();

  if(!pid) {

    if(descendencia < 3) {

      pid = fork();

      if(!pid) {
        printf("Soy hijo%d con PID=%d mi numero aleatorio es %d y el del otro proceso es \n",descendencia,getpid(),rand() % 20);
      } else {
        waitpid(pid,NULL,0);
      }
    }

    descendencia++;

  } else {



    waitpid(pid, NULL, 0);
  }



  return 0;
}