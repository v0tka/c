#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define PROMPT "$ "
#define BUFF_SIZE 1024

// Headers:
void type_prompt(void);
void read_command(char*,char**);

// Definiciones:
void type_prompt(){
	printf(PROMPT);
	fflush(stdout);
}

void read_command(char*command,char**parameters){
	char buff[BUFF_SIZE];
	int c;
	c = read(0,buff,BUFF_SIZE);
	buff[c-1] = '\0';

	// Tokenizar entrada de usuario:
	const char separador[] = " ";
	char* token;
	int i = 0;
	token = strtok(buff,separador);

	if (!strcmp(token,"exit")) {
		exit(EXIT_FAILURE);
	}

	while(token != NULL){
		// Reservar memoria siguiente parámetro:
		parameters[i] =
		   (char*)malloc(sizeof(char)*strlen(token));
		// Copiar token a la celda del parámetro:
		strcpy(parameters[i],token);
		i++;
		// Obtener siguiente token:
		token = strtok(NULL,separador);
	}

	// Copiar contenido de buff a command:
	strcpy(command,parameters[0]);
}

int main(void){
	char *command = (char*)malloc(sizeof(char)*BUFF_SIZE);

	char **parameters = (char**)malloc(sizeof(char*)*10);

	int status;

	while(TRUE){
		type_prompt();
		read_command(command,parameters);

		if(fork()!=0){
			// Código del proceso original:
			//printf("proceso original esperando...");
			waitpid(-1,&status,0);
			if (status == EXIT_FAILURE) {
				return 0;
			}
			//printf("proceso original listo.");
		}else{
			// Código del proceso clon:
			//printf("proceso clon");
			execvp(command,parameters);
			perror("execvp");
		}
	}
	/*type_prompt();
	read_command(command,NULL);
	printf("|%s|\n",command);*/
}
