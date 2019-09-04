#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <dirent.h>
#include <sys/sysinfo.h>

int main(int argc, char* argv[]) 
{
    char* readInput = strchr(getenv("QUERY_STRING"),'=')+1; //apunta antes del nombre
    char *inputParse = strdup(readInput);
    char *name=strtok(inputParse,"&");//me quedo con el nombre completo antes de remover

    char mod_remover[100]={0};
    
    system("sudo dmesg -C"); //limpio mensajes

    strcpy(mod_remover,"sudo rmmod "); 
    strcat(mod_remover,name); //armo comando para system
    system(mod_remover); //ejecuto system para remover modulo 

    system("sudo dmesg");    //imprimo mensajes 

    return 0;
}

