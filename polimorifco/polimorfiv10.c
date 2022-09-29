#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

/*Leer hasta que encuetre 4 nop codigo 90
 leer clave de descrifrado
 descifrar
 copiar a un ejecutable distinto y poner a correr
 cifrar de nuevo
 cerrar
 */

/*Idea:
 el programa se ejecuta por primera vez
 utilizando la clave se descifra, escribe a un archivo nuevo con clave nueva y ejecuta 
 el original cambia su clave y se cierra.
 
 */

int main(int argc,char **argv)
{
unsigned char clave=0x00;   
int i=0;
int a=0x1;
int b=0x2;
int c=0x3;
unsigned char lei[3];
int toktok=0;
FILE *aFile;
char * trabajo=0;
long inicifra=0;
long fincifra=0;
/*
 *    Inicio del codigo a mutar 
 * nop
 * nop
 * nop
 * clave
 * nop
 */
aFile = fopen("eje", "rw");
//printf("%p\n",aFile);
 while (toktok==0 && feof(aFile) == 0 )  
 {
     
     fread(&(lei[i]), 1, 1, aFile );
     //printf("%hhx ",(unsigned int)lei[i]);
     printf("%hhx \t",(unsigned int)lei[0]);
     printf("%hhx \t",(unsigned int)lei[1]);
     printf("%hhx \n",(unsigned int)lei[2]);
     
     if(i==2)
        {
        i=0;
        }else
        {
        i++;   
        }
     if(lei[0]==0x90 && lei[1]==0x90 && lei[2]==0x90  )
     {
         toktok=1;
         printf("Encontrado Inicio\n");
    }
 }
 inicifra=ftell(aFile);//guardo orden de bytes inicial a crifrar
 
 //Busco token de finalizacion
    toktok=0;i=0;
   while (toktok==0 && feof(aFile) == 0 )  
 {
     
     fread(&(lei[i]), 1, 1, aFile );
     //printf("%hhx ",(unsigned int)lei[i]);
     printf("%hhx \t",(unsigned int)lei[0]);
     printf("%hhx \t",(unsigned int)lei[1]);
     printf("%hhx \n",(unsigned int)lei[2]);
     
     if(i==2)
        {
        i=0;
        }else
        {
        i++;   
        }
     if(lei[0]==0x90 && lei[1]==0x90 && lei[2]==0x90  )
     {
         toktok=1;
         printf("Encontrado Fin\n");
    }
 }
 
 fincifra=ftell(aFile);//guardo orden de bytes final a crifrar
 
 
 /*podria detectar cuantos bytes hasta el fin copiar bloque cifrar y escribir */
 
 //printf("%p\n",aFile);
 fclose(aFile);
     
 trabajo=(char*)malloc(fincifra-inicifra);
 aFile = fopen("eje", "rw");
 fseek(aFile,inicifra,SEEK_SET);
 fread(trabajo, fincifra-inicifra, 1, aFile );
 fclose(aFile);//leo el trabajo
 
 for(int x=0;x<fincifra-inicifra;x++)
 {
    printf("%hhx ",*(trabajo+x));
}//Aca tengo el trabajo a realizar

printf ("\nLa clave de cifrado es %hhx\n",*(trabajo+1));
clave=*(trabajo+1);

//cifrando
printf("Cifrando\n");
 for(int x=0;x<fincifra-inicifra;x++)
 {
    printf("Inicial: %hhx ",*(trabajo+x));
    *(trabajo+x)=*(trabajo+x)^clave;
    printf("Cifrado %hhx \n",*(trabajo+x));
}

 //Abro para escribir cifrado
 aFile = fopen("ejebak", "rw+");
 fseek(aFile,inicifra,SEEK_SET);
 printf("%ld\n",fwrite(trabajo, fincifra-inicifra, 1, aFile ));
 //Se escribe el cifrado
 //MAL
 fclose(aFile);

//descifrando
//printf("descifrando\n");
 //for(int x=0;x<fincifra-inicifra;x++)
 //{
    //printf("Inicial: %hhx ",*(trabajo+x));
    //*(trabajo+x)=*(trabajo+x)^clave;
    //printf("Cifrado %hhx \n",*(trabajo+x));
//}


 
 free(trabajo);
 
__asm__("nop");
__asm__("nop");
__asm__("nop");
__asm__("mov $0xAA,%al");// B0 00 es el mov al,algo
__asm__("nop");


//inicio del codigo binario a cifrar

printf("Soy un BuenWare\n");//Los literales no se protegen
printf("2222222222222222222222\n");//Los literales no se protegen

a=a+1;
b=b+1;
c=c+1;
printf("%d %d %d\n",a,b,c);

//fin del codigo binario a cifrar

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
