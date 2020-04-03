#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
 
int main( int argc, char *argv[]){
  
  pid_t pid1, pid2;
  int fd[2];
  char mensaje[23];
  pipe(fd);  // fd[0] contiene el descriptor para lectura
  if((pid1 = fork()) == 0){
    close(fd[0]);
    strcpy(mensaje, "Desde el hijo 1: hola!");
    write(fd[1], mensaje, strlen(mensaje));
    close(fd[1]);
  }else{
    if((pid2 = fork()) == 0){
      printf("Desde el hijo 2\n");
      close(fd[1]);
      read(fd[0], mensaje, 23);
      printf("El mensaje leido es = %s\n", mensaje);
      close(fd[0]);
    }
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
  }
  return 0;

}