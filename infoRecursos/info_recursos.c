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
    FILE *top;//, *fp;
    struct sysinfo up_time;
    int error=sysinfo(&up_time);
    if(error!=0)
    {
	printf("error = %d \n", error);
    }
    char lectura[TAM]={0};
    char buffer[TAM]={0};

//------------------------------informacion del CPU
	top = fopen("/proc/cpuinfo", "r");
	fread(lectura, 1, sizeof(lectura) - 1, top);
	strcpy(Datillos.consum_cpu, lectura);
	memset(lectura, '\0', TAM);
	fclose(top);
//------------------------------fecha y hora actual
	time_t myTime;
	myTime = time(NULL);
	printf("\n FECHA Y HORA ACTUAL: %s", ctime(&myTime));
//-----------------------------Uptime(tiempo que lleva desde inicio)
	printf("\n UPTIME(seg): %ld \n", up_time.uptime);
//----------------------------CPU info
	printf("\n CPU CONSUMO : \n\n  %s \n\n", Datillos.consum_cpu);
//----------------------------Memoria
	printf("\n MEMORIA : \n\n  \n\n");
}
