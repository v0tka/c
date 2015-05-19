#include <stdio.h>
#include <signal.h>

int main(int argc, char const *argv[]) {

  int signal;
  int estado;

  if (argv[1]) {
    estado = kill(atoi(argv[1]),SIGINT);

    if(!estado) {
      printf("Se pudo enviar la señal, estado: %d\n",estado);
    } else {
      printf("No se pudo enviar la señal, estado: %d\n",estado);
    }

  } else {
    printf("Sintaxis\n");
    printf("./signal2 pid\n");
  }



  return 0;
}