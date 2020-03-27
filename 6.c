#include<stdio.h> 
#include<unistd.h>
#include <stdlib.h>


int main(){
    pid_t pid;
    int status;

    printf("El id del padre es = %d\n", getpid());
    pid = fork();
    if(pid == 0){
        printf("Id del proceso hijo= %d\n", getpid());
        for(int i = 0; i < 10; i++){
            printf("i = %d\n", i);
        }  
    }else{
        int x = waitpid(pid, &status, 0);
        printf("El valor de status es = %d\n", status);
        printf("el valor de x = %d\n", x);
    }
    
    return 0;
}

/*
Haga un programa, como el del ejercicio anterior, con una breve modificación, la cual consiste en usar waitpid() en lugar de wait().
¿Cuándo podría ser waitpid() útil?

Al igual que wait(), waitpid() sirve para lo mismo, la diferencia respecto a wait() es que waitpid() es que
detiene el proceso que se esta ejecutando y espera por el proceso que se le indique, es decir, no necesariamente va a esperar a que todos los
hijos terminen de ejecutarse sino aquel que fue enviado a la funcion waitpid()


Puede ser util cuando se tienen multiples hijos de un proceso,pero es necesario detener el proceso principial porque es necesario que uno de sus
hijos terminen sin tener que detener el resto de ellos.
*/