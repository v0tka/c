#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

  struct servent *serv_info;
  int fd;

  struct sockaddr_in address;
  struct sockaddr client;

  address.sin_family = AF_INET;
  address.sin_port = serv_info->s_port;
  address.sin_addr.s_addr = INADDR_ANY;

  serv_info = getservbyname("greet","tcp");

  if(serv_info == NULL) {
    printf("Error en la obtencion de la informacion del servidor\n");
  } else {
    printf("Puerto: %d\n",serv_info->s_port);
    printf("Oficial server name: %s\n",serv_info->s_name);
    printf("Alias list: %s\n",serv_info->s_aliases[0]);
    printf("Protocol used: %s\n",serv_info->s_proto);
  }

  fd = socket(AF_INET, SOCK_STREAM, 0);
  printf("%s\n",fd == -1 ? "Error en la apertura del socket" : "Socket Abierto");


  if(bind(fd,(struct sockaddr *)&address, sizeof(address)) == -1) {
    printf("Error\n");
  } else {
    printf("Proceso asociado con socket\n");
  }

  if(listen(fd,1) == -1) {
    printf("Error al escuchar\n");
  }


  int fd_client = -1;
  socklen_t length_client;

  fd_client = accept(fd,(struct sockaddr *)&client,&length_client);
  if(fd_client == -1) {
    printf("Error al aceptar un cliente\n");
  }

  int read_string_length = 0;
  int aux = 0;
  int MAX_LENGTH = 5;
  char buffer[5];

  while(read_string_length < MAX_LENGTH) {
    aux = read(fd_client, buffer + read_string_length, MAX_LENGTH - read_string_length);

    if(aux > 0) {
      read_string_length += aux;
    } else {
      if(aux == 0) {
        printf("Socket cerrado\n");
      } else if(aux == -1) {
        printf("Error del socket del cliente en la lectura\n");
      }
    }
  }

  int wrote_string_length = 0;
  aux = 0;
  char data[] = "Hola";

  while(wrote_string_length < MAX_LENGTH) {
    aux = write(fd_client, data + wrote_string_length, MAX_LENGTH - wrote_string_length);
    if(aux > 0) {
      wrote_string_length += aux;
    } else {
      if(aux == 0) {
        printf("Socket cerrado\n");
      } else {
        printf("Error del socket del cliente en la escritura\n");
      }
    }
  }

  close(fd_client);


  return 0;
}