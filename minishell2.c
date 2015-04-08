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
  printf(PROMPT);
}

void read_command(char *,char **);
void read_command(char *command, char **parameters) {
  char buff[BUFF_SIZE];
  int bread;
  bread = read(0,buff,BUFF_SIZE);
  buff[bread-1] = '\0';
  strcpy(command,buff);
}

int main(int argc, char const *argv[]) {
  char *command = (char*)malloc(sizeof(char) * (BUFF_SIZE));
  char **parameters;
  int status;


  while (TRUE) {
    if (fork() == 0) {
      type_prompt();
      read_command(command,parameters);
      printf("%s\n",command);
      exit(0);
    } else {
      waitpid(-1,&status,0);
    }
  }

  free(command);
  return 0;
}
