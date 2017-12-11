#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>

#define KEY 1010

int main(int argc, char* argv[]) {

  int sem;
  int N;
  int s;
 
  if (!strcmp(argv[1], "-c")){
    sscanf(argv[2],"%d",&N);
    sem = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0600);
    semctl(sem, 0, SETVAL, N);
    s = semctl(sem, 0, GETVAL);
    printf("semaphore created: %d\n", KEY);
    printf("value set: %d\n", s);   
  }
  
  else if(!strcmp(argv[1], "-v")){
    sem = semget(KEY ,0,0);
    s = semctl(sem, 0, GETVAL);
    printf("semaphore value: %d\n", s);
  }
  
  else if (!strcmp(argv[1], "-r")) {
    sem = semget(KEY, 0, 0);
    s = semctl(sem, 0, IPC_RMID);
    printf("semaphore removed: %d\n", s);
  }
  
  return 0;
}
