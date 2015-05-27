#include <stdio.h>
#include <netdb.h>

int main(int argc, char const *argv[]) {
  struct servent *serv_info;
  struct hostent *host;
  host = gethostbyname("localhost");
  serv_info = getservbyname("greet","tcp");
  fd = socket(AF_INET, SOCK_STREAM, 0);

  if(serv_info == NULL) {
    printf("Error en la obtencion de la informacion con el servidor\n");
  } else {
    printf("Puerto %d\n",serv_info->s_port);
  }

  if(host == NULL) {
    printf("Error en la obtencion de la IP del servidor\n");
  }

  if(fd == -1) {
    printf("Error en la apertura del socket\n");
  }


  return 0;
}