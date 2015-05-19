#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  char entrada[50];
  int status;




  while(1) {

    printf("Ingrese palabra: ");
    scanf("%s",entrada);
    fflush(stdin);

    if (fork() == 0) {

      char *arguments[] = {"/home/mypc/repositories/linux/ejercicio",entrada,NULL};
      execvp("ejercicio", arguments);

      return 0;

    } else {

      waitpid(-1,&status,0);

    }

  }

  return 0;
}


460 Wats 2x fuentes de poder
25  Wats Master View Max KVM
382 Wats Switch hp "2530"
