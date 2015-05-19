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
  pid_t pid;


  pid = fork();

  if(pid == (pid_t)0) {
    printf("Hijo\n");

    int fds[2];
    pipe(fds);


    pid = fork();

    if(pid == (pid_t)0) {

      FILE* stream;
      close(fds[0]);

      stream = fdopen(fds[1], "w");
      srand(time(NULL));

      char *msg = (char*)malloc(sizeof(char)*1024);

      sprintf(msg, "Soy el hijo %d con PID=%d, mi numero aleatorio es %d y el del otro proceso es %d",1,getpid(),rand() % 100,getppid());
      writer(msg,stream);

      close(fds[1]);

    } else {


      FILE* stream;
      close(fds[1]);
      stream = fdopen(fds[0], "r");
      reader(stream);
      close(fds[0]);

    }

  } else {



  }

  return 0;
}
