#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

void writer(const char* message, FILE* stream) {
  fprintf(stream, "%s\n",message);
  fflush(stream);
  sleep(1);
}

void reader(FILE* stream) {
  char buffer[1024];

  while(!feof(stream) && !ferror(stream)
        && fgets(buffer, sizeof(buffer), stream) != NULL) {
    fputs(buffer, stdout);
  }
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int x,y;
  pid_t pid_h2;

  if(!fork()) {
    x = rand() % 100;
    int fds[2];
    pipe(fds);

    pid_h2 = fork();

    if(!pid_h2) {
      y = rand() % 100;

      printf("Soy el hijo 2 con PID=%d, mi numero aleatorio es %d y el del otro proceso es %d\n",getpid(),y,getppid());

      FILE* stream;
      close(fds[0]);

      stream = fdopen(fds[1], "w");
      srand(time(NULL));

      char *msg = (char*)malloc(sizeof(char)*1024);

      sprintf(msg, "Soy el hijo %d con PID=%d, mi numero aleatorio es %d y el del otro proceso es %d",1,getpid(),x,getppid());
      writer(msg,stream);
      close(fds[1]);
      exit(0);

    } else {

      printf("Soy el hijo 1 con PID=%d, mi numero aleatorio es %d \n",getpid(),x);

      FILE* stream;
      close(fds[1]);
      stream = fdopen(fds[0], "r");
      reader(stream);
      close(fds[0]);

    }
  }

  return 0;
}
