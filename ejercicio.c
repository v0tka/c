#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

  if(argc == 2) {

    if (!strcmp(argv[1],"listar_directorio")) {
      execl("/bin/ls", "-1", NULL);
    }

    if (!strcmp(argv[1],"listar_procesos")) {
      execl("/bin/ps", "-1", NULL);
    }

    if (!strcmp(argv[1],"mostrar_ruta_actual")) {
      execl("/bin/pwd","-1", NULL);
    }

    if (!strcmp(argv[1],"mostrar_tiempo")) {
      execl("/bin/date","-1", NULL);
    }

    if (!strcmp(argv[1],"test")) {
      execl("/bin/ls","l","-1",NULL);
    }

  } else {
    printf("Uso\n./ejercicio comando\n");
    fflush(stdout);
  }


  return 0;
}