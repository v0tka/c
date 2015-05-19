#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define PROMPT "$ "
#define TRUE 1
#define BUFF_SIZE 1024

void type_prompt();
void type_prompt() {
  printf("$ ");
}

int read_command(char *,char **);
int read_command(char *command, char **parameters) {
  char buff[BUFF_SIZE];
  int bread;
  bread = read(0,buff,BUFF_SIZE);
  buff[bread-1] = '\0';

  // Tokenizar entrada de usuario
  const char separador[] = " ";
  char *token;
  int i = 0;

  token = strtok(buff,separador);

  if (!strcmp(token,"exit")) {
    return 1;
  }

  strcpy(command,token);
  while (token != NULL) {
    // Reservar memoria en siguiente celda
    parameters[i] = (char*)malloc(sizeof(char)*strlen(token));

    // Copiar token a la celda del parametro
    strcpy(parameters[i++],token);

    // obtener siguiente token
    token = strtok(NULL,separador);
  }

  return 0;

}

int main(int argc, char const *argv[]) {

  if (argv[1]) {
    printf("%s ",argv[1]);
    fflush(stdout);
  } else {
    printf("$ ");
  }

  char *command = (char*)malloc(sizeof(char) * (BUFF_SIZE));
  char **parameters = (char**)malloc(sizeof(char*) * 10);
  int status;

  while (TRUE) {
    if (fork() == 0) {
      // type_prompt();

      if (read_command(command,parameters)) {
        exit(EXIT_FAILURE);
      } else {
        execvp(command,parameters);
      }

      exit(EXIT_SUCCESS);

    } else {

      waitpid(-1,&status,0);

      if (status == EXIT_FAILURE) {
        return 0;
      }

    }
  }

  free(command);
  return 0;
}
