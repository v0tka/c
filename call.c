#include <linux/unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

  //int i = 0;
  /*pid_t proceso;

  for (i; i < 10000; ++i)
  {
    proceso = fork();
  }
  */

  pid_t proceso = fork();

  if (proceso == 0) {
    printf("Soy el hijo\n");
  } else {
    printf("Soy el padre y he creado a mi hijo con el PID %d\n",proceso);
  }

  return 0;
}