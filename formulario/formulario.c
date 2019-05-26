#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <dirent.h>

int main(int argc, char* argv[]) 
{
	char* readInput = strchr(getenv("QUERY_STRING"),'=')+1;

	char *inputParse = strdup(readInput);
	char anio[10]={0};
	char dia[10]={0};

	strcat(anio,inputParse);
	strcat(dia,inputParse);

	char * day=strtok(dia,"=");
	day=strtok(NULL," ");

	char *year=strtok(anio,"&");
	printf("El dia es %s \n",day);
	printf("El anio es %s \n",year);
	return 0;

}
