#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

/*Este programa renombra su ejecutable con la hora cada 5 segundos*/

int main()
{
int esprimervez=0;
    

char fechaHorapre[70];
char fechaHora[70];
char *formato = "%Y-%m-%d%H:%M:%S";
char comando[100];



for(;;)
{
time_t t = time(NULL);
struct tm tiempoLocal = *localtime(&t);
strftime(fechaHora, sizeof fechaHora, formato, &tiempoLocal);
strcpy(comando,"mv ");
strcat(comando," ");
    if(esprimervez==0)
    {
    strcat(comando,"eje");
    esprimervez=1;
    }else
    {
        strcat(comando,fechaHorapre);
    }

strcat(comando," ");
strcat(comando,fechaHora);

printf("pre %s\n",fechaHorapre);
printf("pre %s\n",fechaHora);
strcpy(fechaHorapre,fechaHora);

// mv <fechahoraPre> <fechahora>, la primer vez mv eje fechaHora
system(comando);
sleep(5);
}



}
