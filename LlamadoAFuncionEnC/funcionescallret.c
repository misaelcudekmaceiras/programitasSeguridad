
/*
 Para compilar gcc -o eje funcionescallret.c
 Para obtener el assembly gcc -S -masm=intel -fverbose-asm funcionescallret.c
 Para ejecutar ./eje , este programa no tiene salida en pantalla.
 
 
 Programa para analizar los llamados a funciones , a traves de la observacion del codigo assembly generado por el
 compilador.
 Se observa el uso de call, ret , y el uso de registros del microprocesador para el pasaje de variables.
 */


#include<stdio.h>

int suma(int,int);

int main()
{

int v1=16;
int v2=32;
int v3=0;
v3=suma(v1,v2);
//return(0);
}

int suma(int a,int b)
{
int c=0;
c=a+b;
return(c);
}
