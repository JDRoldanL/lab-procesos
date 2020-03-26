#include <stdio.h>
#include <unistd.h>

int main(){
    pid_t  pid;
    int x = 100;
    pid = fork();
    if(pid == 0){
        x = x + 1;
    }else{
        x = x + 2;
    }
    printf("El valor de x = %d\n", x);
    return 0;
}


/*
    ¿Cuál es el valor de la variable en el proceso hijo?
        La valriable de x = 100, es el mismo en ambos proceso, en el padre y en el hijo.
    
    ¿Qué sucede con la variable cuando el proceso hijo y el padre cambian el valor de x?
        Cuando se cambia la variable en el proceso hijo este aumenta la variable en 1 y su valor retorna 101,
        sin embargo, cuando se cambia en el padre y se hace un incremento de 2, como el valor era el mismo
        para ambos(de 100), esta queda valiendo 102 y no 103.
    
*/