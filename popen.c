#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  FILE* stream = popen("sort", "w");
  fprintf(stream, "This is a test\n");
  fprintf(stream, "hello, world\n");
  fprintf(stream, "my dog has fleas\n");
  fprintf(stream, "this program is great\n");
  fprintf(stream, "one fish, two fish\n");
  fprintf(stream, "Hello world\n");
  return pclose(stream);
}