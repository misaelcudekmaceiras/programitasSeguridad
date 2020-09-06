#include<stdio.h>
#include<string.h>



int main()
{
    char  texto[]="abcdefghijklmnopqrstuvwxyz";
    char cifrado[strlen(texto)+1];
    cifrado[strlen(texto)]='\0';
    printf("Mensaje original \t%s\n",texto);
    
    for(int i=0;i<(strlen(texto));i++)
    {
        cifrado[i]=texto[i]+3;//asi se escapa de las letras
    }
    
    printf("Mensaje cifrado \t%s\n",cifrado);
    
    for(int i=0;i<strlen(texto);i++)
    {
            cifrado[i]='a'+(  (texto[i]+3-'a')%('z'-'a'+1)  );// z:122 a:97 z-a:25 
    }
    
    printf("Mensaje cifrado \t%s\n",cifrado);
    
    
    return(0);
}
