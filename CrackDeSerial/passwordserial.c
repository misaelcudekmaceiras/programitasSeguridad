#include<stdio.h>
#include<string.h>

/*
 Para compilar este programa gcc -o eje password.c
 Este programa tiene el fin de introducir las bases del crack de un programa, dado que tiene un serial para su funcionamiento
 En este simple ejemplo, el usuario para utilizar el programa, debe ingresar una contraseña/Serial, que responde a un algoritmo Ultimos caracteres iguales y la resta entre los primeros dos debe ser 0x1C
 Es decir que hay un conjunto de combinaciones posibles que valida el uso del programa.
 A continuacion modificaremos el binario para que cualquier combinacion de 4 caracteres sea un serial valido
 
 Se propone:
 1)que descargue el compilado de github
 2)Ejecute en la terminal objdump -d eje (se provee el ejericio resuelto en un archivo de volcado)
 3)ubique dentro de la "memoria del programa", el sector main
 4)ubique el llamado a alguna funcion que sirva para la verificacion de un serial
 5)Conociendo el mecanismo de pasaje de argumentos a funciones de C, ubique que registros del microprocesador se cargan como parametros.
 6)Siga el codigo desensamblado para hacia atras persiguendo de donde vienen los valores que en ultima instancia se mandan a la funcion.
 7)Habiendo verificado sea la funcion que valida el serial, ubique las ultimas lineas de codigo
 8)Sabiendo que en caso de devolver un int,boolean,char, el compilador guarda en el registro eax el valor del return(int), analize que valor parece ser el enviado en caso de serial correcto.
 9)Abra el binario compilado del programa con $ ghex eje
 10)Para este programa se observa en el archivo de volcado obtenido del hexdump que las lineas 89e y 8a5 cargan un valor de 0x0 en eax, esto corresponde cono los return(0), caso de ser falsa la contraseña
 11)En el programa ghex que tiene abierto, ubique:
    -> a los bytes correspondientes de las instruciones "b8 00..", ubicadas en el byte inidice 89905 del binario y reemplaze por "b8 01 .." (equivalente a return(1))
    -> a los bytes correspondientes de las instruciones "b8 00..", ubicadas en el byte inidice 8990C del binario y reemplaze por "b8 01 .." (equivalente a return(1))
 
 Como referencia puede utilizar los codigos de operacion de los jmp superiores a cada "mov 0,eax"  "EB 0C" y "EB 05"
 12)En el menu del ghex guarde el archivo como nombre ejecracked
 13)En la consola dele permiso de ejecucion como chmod u+x ejecracked.
 14) Ejecute el programa crackeado como $ ./ejecracked  cualquier combinacion de 4 caracteres sera considerado una contraseña valida.
 15)Verifique lo que hizo con $ objdump -d ejecracked , vera como se han modificado los mov
 
 

 
 
 */

int checkPassSerial(char pass[]);

int main()
{
    
    char pass[8];
    
    
    do
    {
    printf("Ingrese la contraseña: ");
    scanf("%s",pass);    
    
    }
    while(checkPassSerial(pass)==0);
    printf("Bienvenido al programa\n");
    
    printf("Cuantas cosas que hace este programa!!!\n");

    
    printf("Fin del programa\n");
    
}

int checkPassSerial(char pass[])
{
    //El password debe tener tamaño 4, los ultimos dos caracteres iguales y la resta entre los dos primeros es 0x1C
    if(strlen(pass)!=4)
    {
        //Si la pass no tienen tamaño 4 esta mal.
        return(0);
    }else
    {
        if(pass[3]==pass[2])
        {
            if(pass[0]==(pass[1]-0x1C))
            {
            return(1);    
            }
            else
            {
                return(0);
            }
        }
        else
        {
            return(0);
        }
    }
    
    return(0);
}

