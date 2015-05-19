#include <stdio.h>
#include <signal.h>

void catch_int(int sig_num) {
  signal(SIGINT, catch_int);
  printf("Don't do that\n");
  fflush(stdout);
}

void catch_signal(int sig_num) {
  signal(10, catch_signal);
  printf("Whoops!!\n");
  fflush(stdout);
}

int main(int argc, char const *argv[]) {

  // signal(SIGINT, catch_int);

  // printf("%d\n",SIGINT );

  // for (;;) {
  //   pause();
  // }


  signal(SIGINT, catch_int);

  for(;;) {
    pause();
  }

  return 0;
}