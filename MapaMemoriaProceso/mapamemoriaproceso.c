#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*Programa para analizar la memoria de un proceso
Para compilar  gcc -c mapamemoriaproceso.c
gcc -o eje mapamemoriaproceso.o

Para generar el archivo de assembly gcc -S -masm=intel -fverbose-asm mapamemoriaproceso.c , luego abrir el mapamemoriaproceso.s

Para analizar antes de ejecutar
objdump -h  mapamemoriaproceso.o
objdump -x  mapamemoriaproceso.o
readelf  -a eje
nm -A eje
Ayuda para el analisis https://en.wikipedia.org/wiki/Data_segment

Para ejecutar ./eje 

0)Corra el programa
1)Luego ejecute en la consola los comandos  $ pmap  `pidof eje`
Se sugiere revisar en profundidad con  pmap -x `pidof eje` ;  pmap -X `pidof eje` ; pmap -XX `pidof eje`

*/

int enterogloblal=0;
char charglobal='G';

int main()
{
    int enterodelmain=1;
    char chardelmain='M';
    
    int * pInt=(int*)malloc(4097);
    
    printf("Hola Mundo!!\n");
    
    printf("dir enterogloblal: %p\n",&enterogloblal);
    printf("dir charglobal: %p\n",&charglobal);
    
    printf("dir enterodelmain: %p\n",&enterodelmain);
    printf("dir chardelmain: %p\n",&chardelmain);
    
    printf("dir &pInt: %p\n",&pInt);
    printf("dir pInt: %p\n",pInt);
    
    printf("dir prinf: %p\n",printf);
    printf("dir main: %p\n",main);
    
    
    getchar();//para que no finalice el programa
    
}
