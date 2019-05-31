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
    FILE *top;//, *uptime;
	struct sysinfo up_time;
	int error=sysinfo(&up_time);
	if(error!=0)
	{
		printf("error = %d \n", error);
	}
    char lectura[TAM]={0};
    char comando[TAM]={0};
	char comando_aux[TAM]={0};

    //--------tiempo que lleva activo
	/*strcpy(comando, "ps -p ");
	sprintf(comando_aux, "%ld", (long)getpid());
	strcat(comando, comando_aux);
	strcat(comando," -o etime= ");
	strcat(comando," >> ./uptime.info");
	system("rm ./uptime.info");
	system(comando);
	uptime = fopen("./uptime.info", "r");
	fread(lectura, 1, sizeof(lectura) - 1, uptime);
	strtok(lectura, "\n");
	strcpy(Datillos.uptime, lectura);
    memset(lectura, '\0', TAM);//limpio buffer de lectura
	fclose(uptime);*/

    //obtengo de ps(process status) la informacion actual
	//de mi proceso. Donde vsize: tamanio de memoria virtual del proceso en KB,
	//pid: es el id de mi proceso y pcpu: es el %cpu del mismo
	
	//strcpy(comando, "ps -Ao vsize,pid,pcpu | grep ");
//	sprintf(comando_aux, "%ld", (long)getpid());
//	strcat(comando, comando_aux);
//	strcat(comando," >> ./top.info");
//	system("rm ./top.info");
//	system(comando);
	
	top = fopen("/proc/cpuinfo", "r");
	fread(lectura, 1, sizeof(lectura) - 1, top);
//	strtok(lectura, "\n");
	strcpy(Datillos.consum_cpu, lectura);
	memset(lectura, '\0', TAM);
	fclose(top);

	//----------------------fecha y hora actual
	time_t myTime;
	myTime = time(NULL);
	printf("\n Fecha y hora actual: \n %s \n", ctime(&myTime));
	printf("\n Uptime (seg): \n %ld \n", up_time.uptime);
	printf("\n Info CPU : \n %s \n", Datillos.consum_cpu);
}
