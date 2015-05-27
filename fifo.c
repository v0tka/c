#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[]) {

  FILE* mipipe;

  char buffer[128];
  int i = 0;

  if(mkfifo("pipetest", S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH) != 0) {
    printf("Hubo un problema al crear la pipe\n");
  }

  mipipe = fopen("pipetest","w");

  while(i < 10) {
    sprintf(buffer, "CADENA ENVIADA - Numero: %i\n",i++);
    fputs(buffer,mipipe);
  }

  fclose(mipipe);

  return 0;
}