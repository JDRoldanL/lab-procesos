#include<stdio.h>
#include<unistd.h>

int main(){
    
    if(fork() == 0){
        close(STDOUT_FILENO);
        printf("Soy el hijo\n");
    }else{
        printf("Soy el padre\n");
    }
    return 0;
}


/*
    Escriba un programa que cree un proceso hijo y entonces en el proceso hijo cierre la salida estandar (STDOUT FILENO).
    ¿Qué pasa si el hijo llama printf() para imprimir alguna salida después de cerrar el descriptor?

    Lo que sucede cuando el hijo cierra el descriptor, es que no puede usar la funcion printf(),
    impidiendo que se pueda hacer uso del write que es un syscall
    
*/