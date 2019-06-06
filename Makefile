#Makefile de Trabajo Practico N°3 de Sistemas Operativos

all: maketodo

maketodo : 
	gcc -Wall -Werror -pedantic -o ./infoRecursos/eRecursos.cgi ./infoRecursos/info_recursos.c
	gcc -Wall -Werror -pedantic -o ./formulario/eFormulario_v2.cgi ./formulario/formulario_v2.c
	gcc -Wall -Werror -pedantic -o ./modulitos/eModulitos.cgi ./modulitos/modulitos.c

clean:
	rm ./infoRecursos/eRecursos.cgi \
	rm ./formulario/eFormulario_v2.cgi \
	rm ./modulitos/eModulitos.cgi \
