#include<stdio.h>
#include<string.h>

/*
 Para compilar este programa gcc -o ejecutable guardasinconsenti.c

 Este programa envia la informacion ingresada por el usuario , y el resultado del procesamiento a un archivo oculto
 

0)ejecutar el programa.
1)Ejecutar en la misma ruta donde se ejecuto el programa ls -la
 
Se sugiere investigar con lsof -c ejecutable , para explicar como se ven archivos abiertos por programas.
Serviria para probar un programa del tipo HIDS
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
    
    printf("Fin del programa\n");
    
}
