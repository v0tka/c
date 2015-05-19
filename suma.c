#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>

int main(int argc, char const *argv[]) {
	
	pid_t pID;
	int status,a=7,b=4;
	printf("Realizando suma...\n");
	pID = fork();

	if(pID == 0) {
		printf("Sumando %d + %d\n",a,b);
		exit(a+b);
	} else {
		waitpid(pID,&status,0);
		printf("El resultado es: %s\n",WSTOPSIG(status));
	}

	return 0;
}