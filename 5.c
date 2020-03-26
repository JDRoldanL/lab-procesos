#include<stdio.h> 
#include<unistd.h>
#include <stdlib.h>


int main(){
    pid_t pid;
    printf("El id del padre es = %d\n", getpid());
    pid = fork();
    if(pid == 0){
        printf("Id del proceso hijo= %d\n", getpid());
        int w = wait(NULL);
        printf("El valor de w es = %d\n", w);
    }else{
        int x = wait(NULL);
        printf("el valor de x = %d\n", x);
    }
    
    return 0;
}

/*
Escriba ahora un programa que use wait() para esperar que el proceso 
hijo finalice su ejecución. ¿Cuál es el valor de retorno de la función 
wait()?, ¿Qué pasa si usted usa la función wait en el hijo?


La funcion wait retorna la ID del proceso secundario ejecutado.
Si la funcion wait() es usada dentro de un proceso hijo que no crea mas procesos
retornara -1 como se puede observar.
*/