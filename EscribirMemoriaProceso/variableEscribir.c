#include<stdio.h>
#include<stdlib.h>
#include <sys/io.h>

int main()
{
    int * pVar=0;
    int valor=0;
    printf("Prioridad cambiada %d\n",iopl(3)); 
    while(1)
    {
    printf("Ingrese direcion de memoria en hexadecimal\n");
    __fpurge(stdin);
    scanf("%p",&pVar);
    
    
    asm ("movq %1, %%rbx;"
         "movq (%%rbx), %0;"
         : "=r" ( valor )        /* output */
         : "r" ( pVar )         /* input */
         : "%ebx"         /* clobbered register */
     );
    
    
    printf("Valor dentro %d\n",*pVar);
   //rintf("Ingrese valor int\n");
   //scanf("%d",pVar);
    sleep(1);    
    }
    
}
