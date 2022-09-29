#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>



int main(int argc,char **argv)
{
int i=0;
int a=0x1;
int b=0x2;
int c=0x3;
unsigned char lei[3];
int toktok=0;
FILE *aFile;
/*
 *    Inicio del codigo a mutar 
 * nop
 * nop
 * nop
 * clave
 * nop
 */
aFile = fopen("eje", "rw");
printf("%p\n",aFile);
 while (toktok==0 && feof(aFile) == 0 )  
 {
     
     fread(&(lei[i]), 1, 1, aFile );
     printf("%hhx ",(unsigned int)lei[i]);
     if(i%3)
        {
        i=0;
        }else
        {
        i++;   
        }
     if(lei[0]==0x90 && lei[1]==0x90 && lei[2]==0x90  )
     {
         toktok=1;
         printf("Encontrado\n");
    }
 }
 printf("%p\n",aFile);
 fclose(aFile);
     
__asm__("nop");
__asm__("nop");
__asm__("nop");
__asm__("mov $0x12345678aabbccdd,%rax");// 48 B8 es el mov rax,algo
__asm__("nop");

/*Leer hasta que encuetre 4 nop codigo 90
 leer clave de descrifrado
 descifrar
 copiar a un ejecutable distinto y poner a correr
 cifrar de nuevo
 cerrar
 */

printf("Soy un BuenWare\n");//Los literales no se protegen
printf("2222222222222222222222\n");//Los literales no se protegen

a=a+1;
b=b+1;
c=c+1;
printf("%d %d %d\n",a,b,c);


__asm__("nop");
__asm__("nop");
__asm__("nop");
__asm__("nop");

/*Fin del codigo a cifrar
 nop
 nop
 nop
 nop*/

}
