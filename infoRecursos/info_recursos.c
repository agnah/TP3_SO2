#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>
#include <sys/sysinfo.h>

#define TAM  3096
struct datillos
{
    char uptime[TAM];
    char consum_cpu[TAM];
}Datillos;

int main(int argc, char *argv[])
{
    FILE *top, *fp;
    struct sysinfo up_time;
    int error=sysinfo(&up_time);
    if(error!=0)
    {
	printf("error = %d \n", error);
    }
    char lectura[TAM]={0};
    //char buffer[TAM]={0};
    char comando[TAM];
    char comando_aux[TAM];
//------------------------------informacion del CPU
	top = fopen("/proc/cpuinfo", "r");
	fread(lectura, 1, sizeof(lectura) - 1, top);
	strcpy(Datillos.consum_cpu, lectura);
	memset(lectura, '\0', TAM);
	fclose(top);
//------------------------------fecha y hora actual
	time_t myTime;
	myTime = time(NULL);
	printf("\n\nFECHA Y HORA ACTUAL: %s \n\n", ctime(&myTime));
//-----------------------------Uptime(tiempo que lleva desde inicio)
	printf("UPTIME(seg): %ld \n\n", up_time.uptime);
//----------------------------CPU info
	//printf("\n CPU CONSUMO : \n\n  %s \n\n", Datillos.consum_cpu);
//----------------------------Memoria
	strcpy(comando, "ps -Ao vsize,pid,pcpu | grep ");
	sprintf(comando_aux, "%ld", (long)getpid());
	strcat(comando, comando_aux);
	strcat(comando," >> ./top.info");
	system("rm ./top.info");
	system(comando);
	fp = fopen("./top.info", "r");
	fread(lectura,1, sizeof(lectura) - 1, fp);
	strtok(lectura, "\n");
	strcpy(Datillos.consum_cpu, lectura);
	memset(lectura, '\0', TAM);
	fclose(fp);

	printf("\nMEMORIA | PID | CPU : %s \n\n",Datillos.consum_cpu);
}
