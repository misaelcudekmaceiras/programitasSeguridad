#include<stdio.h>
#include<stdlib.h>

/*sudo dd bs=1 skip="$((0x7ffcc2bfdd9e))" count=9 if="/proc/49582/mem" |   od -c
*/


int main()
{
    char contra[]="AaBb123Cc";
    while(1)
    {
    printf("Direcion: %p Valor:%s\n",&contra,contra);
    sleep(1);    
    }
    
}
