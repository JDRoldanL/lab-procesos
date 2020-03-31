
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
        //char *args[] = {"/bin/ls", "-l", ".", NULL};
        printf("Soy el padre empezando\n");
        pid_t pid;
        pid = fork();
        if(pid == 0){
                
                printf("Execl: \n");
                execl("/bin/ls", "/bin/ls", "-l", ".", NULL);

                //printf("Execlpl: \n");
                //execlp("/bin/ls", "/bin/ls", "-l", ".", NULL);

                //printf("Execle: \n");
                //execle ("/bin/ls", "/bin/ls", "-l", ".", NULL, env);


                //printf("Execv: \n");
                //execv("/bin/ls", args);


                //printf("Execvp: \n");
                //execvp("/bin/ls", args);

                //printf("Execve: \n");
                //execve("/bin/ls", args3, env);


        }else{
                wait(NULL);
                printf("FIN\n");
        }
        return 0;

}


/*

Esta familia de funciones, reemplaza la imagen de memoria actual del proceso con una nueva imagen de memoria.
En caso de que la llamada a la función sea correcta esta no retorna nada, si hay una falla el valor retornado será -1.
Se usa la funcion wait para que el padre puedar terminar de ejecutarse.
Lo diferente de cada una de estas funciones es como es llamada o invocada ya que cada una recibe parametros diferentes.

*/