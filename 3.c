#include <stdio.h>
#include <unistd.h>

int main(){
    if(fork() == 0){
        printf("Hello\n");
    }else{
        sleep(2);
        printf("Goodbye\n");
    }
    return 0;
}

/*
    Se puede hacer que el proceso hijo escriba primero, si el proceso padre
    es detenido por el suficiente tiempo para que el hijo termine, en este caso
    usando un sleep de 2 segundos para el proceso padre.
*/