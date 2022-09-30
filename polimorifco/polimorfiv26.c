#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

/*
  Inicia un programa sin cifrar
  Este duplica su ejecutable pero cifrado 
  
  Si se ejecuta el duplicado cifrado, el se vuelve a duplicar con otra clave ,  y se duplica sin cifrar 

 
 */



long buscarInicio(char *);
long buscarFin(char *,long);
void construirComando(char *,char**,char *);
void escribirArchivoCifrado(char *,char *,long,long);
void cargarTrabajo(char * nombre,char *trabajo,long fin,long ini);



void cifrar(char *,unsigned char,long);




//v16 explota la creacion de la copia

int main(int argc,char **argv)
{
   int frk=0;
unsigned char clave=0x00;   
char clavestring[5];//  0xAA
clavestring[1]='\0';
char comando[100];
char nombreNuevo[50];
int i=0;
int a=0x1;
int b=0x2;
int c=0x3;
unsigned char lei[3];
int toktok=0;
FILE *aFile=0;
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

if(!strcmp(argv[0],"./eje") )
{
   //primera ejecu solo cifrar
   
inicifra=buscarInicio("eje");
fincifra=buscarFin("eje",inicifra);
 
trabajo=(char*)malloc(fincifra-inicifra);
  
cargarTrabajo("eje",trabajo,fincifra,inicifra);

printf ("\nLa clave de cifrado es %hhx\n",*(trabajo+1));
clave=*(trabajo+1);
//clavestring[0]=(clave&0x0F)+'a';
sprintf(clavestring,"%hhx",clave);
//printf("La clave string es %s\n",clavestring);
//getchar();

construirComando(comando,argv,clavestring);
system(comando);//copie el binario del programa a otro archivo con el mismonombre+clave

printf("Cifrando\n");
cifrar(trabajo,clave,fincifra-inicifra);//estoy cifrando la clave no deberia.

strcpy(nombreNuevo,argv[0]);
strcat(nombreNuevo,clavestring);
escribirArchivoCifrado(nombreNuevo,trabajo,inicifra,fincifra);
 
free(trabajo);
}else
{
   printf("\nSegunda Ejecu AAA\n");
   //deberia descrifrase, clonarse sin cifrar
   //deberia clonarse cifrado con nueva clave

   inicifra=buscarInicio(argv[0]);
   fincifra=buscarFin(argv[0],inicifra);

   trabajo=(char*)malloc(fincifra-inicifra);

   cargarTrabajo(argv[0],trabajo,fincifra,inicifra);

   printf ("\nLa clave de cifrado es %hhx\n",*(trabajo+1));
   clave=*(trabajo+1);
   //sprintf(clavestring,"%hhx",clave);
   strcpy(clavestring,"sin");

   construirComando(comando,argv,clavestring);
   system(comando);//copie el binario del programa a otro archivo con el mismonombre+clave

   printf("Descrifrando\n");
   cifrar(trabajo,clave,fincifra-inicifra);
   
   

   strcpy(nombreNuevo,argv[0]);
   strcat(nombreNuevo,"sin");
   escribirArchivoCifrado(nombreNuevo,trabajo,inicifra,fincifra);
   printf("Clon creado sin cifrado\n");
   
   *(trabajo+1)=*(trabajo+1) +1; //sumo 1 a la clave
   clave=*(trabajo+1); 
   
   sprintf(clavestring,"%hhx",clave);
   construirComando(comando,argv,clavestring);
   system(comando);//copie el binario del programa a otro archivo con el mismonombre+clave
   //crifrando con nueva clave
   cifrar(trabajo,clave,fincifra-inicifra);
   strcpy(nombreNuevo,argv[0]);
   strcat(nombreNuevo,clavestring);
   escribirArchivoCifrado(nombreNuevo,trabajo,inicifra,fincifra);
   printf("Clon creado con cifrado\n");
   
   exit(0);//Lo finalizo porque esta ejecucion tiene el binario cifrado, si llego hasta aca debe existir un nuevo archivo sin cifrar

   //segunda ejecu
   //descifrar escribir ejecutar
   //cifrar con otro nombre
   //cerrar
}

 

 
__asm__("nop");
__asm__("nop");
__asm__("nop");
__asm__("mov $0xAA,%al");// B0 00 es el mov al,algo  algo es la clave, clave inicial:AA
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



}


/**Funciones**/


void cargarTrabajo(char * nombre,char *trabajo,long fin,long ini)
{
   FILE * aFile = fopen(nombre, "rw");
   fseek(aFile,ini,SEEK_SET);
   fread(trabajo, fin-ini, 1, aFile );
   fclose(aFile);//leo el trabajo
}

void cifrar(char * trabajo,unsigned char clave,long tam)
{
      //Arranco en 3 para saltear 90 90 90 B0 <clave> 90
      for(int x=3;x<tam;x++)
      {
         // printf("Inicial: %hhx ",*(trabajo+x));
         *(trabajo+x)=*(trabajo+x)^clave;
         // printf("Cifrado %hhx \n",*(trabajo+x));
      }
}

void escribirArchivoCifrado(char * nombreArch,char * datoCifrado,long inicio,long fin)
{
   FILE * aFile = fopen(nombreArch, "rw+");
   //printf("aFile %p\n",aFile);
   fseek(aFile,inicio,SEEK_SET);
   //printf("\nEscribiendo\n");
   printf("%ld\n",fwrite(datoCifrado, fin-inicio, 1, aFile ));
   fclose(aFile);
   printf("\nEscrita copia cifrada\n");
}

long buscarFin(char *archivo,long desde)
{
   int toktok=0,i=0;
   FILE *aFile=0;
   unsigned char lei[3]; 
   long posi=0;

   aFile = fopen(archivo, "rw");
   fseek(aFile,desde+1,SEEK_SET);//busca token de fin desde el inicio+1

 while (toktok==0 && feof(aFile) == 0 )  
 {
     
     fread(&(lei[i]), 1, 1, aFile );
     //printf("%hhx ",(unsigned int)lei[i]);
     //printf("%hhx \t",(unsigned int)lei[0]);
     //printf("%hhx \t",(unsigned int)lei[1]);
     //printf("%hhx \n",(unsigned int)lei[2]);
     
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
 posi=ftell(aFile)-3; //Me quedo corrido 3 nop por culpa del algoritmo de detecion
 fclose(aFile);
 return(posi);//guardo orden de bytes inicial a crifrar
   
   
}

long buscarInicio(char * archivo)
{
   int toktok=0,i=0;
   FILE *aFile=0;
   unsigned char lei[3]; 
   long posi=0;

   aFile = fopen(archivo, "rw");
//printf("%p\n",aFile);
 while (toktok==0 && feof(aFile) == 0 )  
 {
     
     fread(&(lei[i]), 1, 1, aFile );
     //printf("%hhx ",(unsigned int)lei[i]);
     //printf("%hhx \t",(unsigned int)lei[0]);
     //printf("%hhx \t",(unsigned int)lei[1]);
     //printf("%hhx \n",(unsigned int)lei[2]);
     
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
 posi=ftell(aFile);
 fclose(aFile);
 return(posi);//guardo orden de bytes inicial a crifrar
   
   
}
void construirComando(char * comando,char** argv,char * clavestring)
{
strcpy(comando,"cp "); 
strcat(comando,argv[0]); //nombre ejecutable original
strcat(comando," ");//espacio
strcat(comando,argv[0]);//nombre ejecutable original
strcat(comando,clavestring);//seguido de la clave

//printf("el comando es: %s\n",comando); 
}
