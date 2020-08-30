#include<stdio.h>
#include<string.h>

/*
 Para compilar este programa gcc -o eje password.c
 Este programa tiene el fin de introducir las bases del crack de un programa, dado que tiene un serial para su funcionamiento
 En este simple ejemplo, el usuario para utilizar el programa, debe ingresar una contraseña, que se encuentra enbebida en el codigo fuente, de la forma menos correcta posible(un char[] llamado password)
 
 Se propone:
 1)que descargue el compilado de github
 2)Ejecute en la terminal objdump -d eje (se provee el ejericio resuelto en un archivo de volcado)
 3)ubique dentro de la "memoria del programa", el sector main
 4)ubique el llamado a alguna funcion que sirva para la comparacion de caracteres
 5)Conociendo el mecanismo de pasaje de argumentos a funciones de C, ubique que registros del microprocesador se cargan como parametros.
 6)Siga el codigo desensamblado para hacia atras persiguendo de donde vienen los valores que en ultima instancia se mandan a la funcion.
 7)Recordando el concepto de endianes de un microprocesador,y el formato ascii, identifique la password
 8)Llame a su madre y digale :"mama mama soy un hacker"
 
0)ejecutar el programa.
 
 */

int main()
{
    
    char pass[8];
    char password[]="Mi22";
    
    do
    {
    printf("Ingrese la contraseña: ");
    scanf("%s",pass);    
    
    }
    while(strcmp(pass,password));
    printf("Bienvenido al programa\n");
    
    printf("Cuantas cosas que hace este programa!!!\n");

    
    printf("Fin del programa\n");
    
}

