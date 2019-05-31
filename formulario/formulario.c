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
	system("aws s3 --no-sign-request ls --recursive noaa-goes16/ABI-L2-CMIPF/2018/014/ | grep M3C13 > ./aws");
	printf("Hola \n");
	/*	char* readInput = strchr(getenv("QUERY_STRING"),'=')+1;
	char *inputParse = strdup(readInput);
	char anio[10]={0};
	char dia[10]={0};
	strcat(anio,inputParse);
	strcat(dia,inputParse);
	char * day=strtok(dia,"=");
	day=strtok(NULL," ");
	char *year=strtok(anio,"&");
	printf("Dia del anio: %s \n",day);
	printf("Anio: %s \n",year);
*/
	return 0;
}
