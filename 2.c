#include<stdio.h> 
#include<fcntl.h> 
#include<errno.h> 
#include<string.h> 
#include<unistd.h>

extern int errno; 

int main() {      
    int sz; 
    int fd = open("foo.txt", O_WRONLY | O_CREAT);  
    printf("fd = %d\n", fd); 
    if(fork() == 0){
        sz = write(fd, "Hijo accediendo\n", strlen("Hijo accediendo\n")); 
    }else{
        sz = write(fd, "Padre accediendo\n", strlen("Padre accediendo\n")); 
    }
    printf("return %d\n", sz); 
    close(fd); 
    return 0; 
}

/*

    ¿Pueden el padre y el hijo acceder al file descriptor retornado por open()?
        Si ambos pueden acceder al fd retornado por el open()

    ¿Qué pasa si ellos empiezan a escribir el archivo de manera concurrente, es decir, a la misma vez?
        Como ambos pueden acceder, ambos pueden escribir sobre el archivo como se evidencia el la imagen
        depues de compilar el codigo.

*/