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

int main(int argc, char const *argv[]){
	char *command = (char*)malloc(sizeof(char)*BUFF_SIZE);
	char **parameters = (char**)malloc(sizeof(char*)*10);
	int status;
	const char *user_prompt = argv[1];

	while(TRUE){

	  if (user_prompt) {
	    printf("%s ",user_prompt);
	    fflush(stdout);
	  } else {
			type_prompt();
	  }

		read_command(command,parameters);

		if (!strcmp(command,"exit")) {
			return 0;
	 	}

		if(fork()!=0){
			// Código del proceso original:
			waitpid(-1,&status,0);
		}else{
			// Código del proceso clon:
			execvp(command,parameters);
			perror("execvp");
		}
	}

	return 0;
}
