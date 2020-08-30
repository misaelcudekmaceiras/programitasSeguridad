#include<stdio.h>
/*
 Para compilar: gcc -o eje usomalprintf.c
 Para ejecutar ./ejecutar
 El fin de este programa es mostar como la funcion printf
 continua leyendo la memoria e imprimiendo en la consola
 
 En la consola podria ver:

usando bien al printf por 1 vez
usando mal printf 1° usando mal printf 1° por 1 vez

usando mal printf 2° usando mal printf 2° usando mal printf 1° por 1 vez

 
 
 */

int main()
{
    printf("usando bien %s printf por %d vez\n","al",1);
    printf("usando mal printf 1° %s\n");
    printf("usando mal printf 2° %s\n");
    
    return(0);
}
