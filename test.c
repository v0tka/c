#include <unistd.h>

int main(void)
{
  char *execArgs[] = { "ejercicio", "listar_directorio", NULL };
  execvp("ejercicio", execArgs);

  return 0;
}