#include <stdio.h>
#include <signal.h>

int main(int argc, char const *argv[]) {
  int signal_to_send;
  int estado;

  if (argv[1]) {
    while(1) {
      printf("Ingrese señal a enviar: ");
      scanf("%d",&signal_to_send);
      fflush(stdin);
      estado = kill(signal_to_send,signal_to_send);

      if(!estado) {
        printf("Se pudo enviar la señal, estado: %d\n",estado);
      } else {
        printf("No se pudo enviar la señal, estado: %d\n",estado);
      }
    }
  }

  return 0;
}