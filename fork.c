#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main(){
    printf("Testing forking processes...\n");
    int f;
    int t;

    printf("Initial process pid: %d\n", getpid());
    printf("Forking process with pid: %d \n", getpid());
    f = fork();

    if(f){
        int initial_process = f;
        f=fork();
        // printf("Forked process again \n");

        if(f){
          int status;
          int child_process = wait(&status);
          printf("Child process %d slept for %d seconds \n", child_process, WEXITSTATUS(status));
          return 0;
        }

        else {
          printf("Child process with pid: %d \n", getpid());
          srand(time(NULL));
          t = (rand() % 16) + 5;
          sleep(t);
          printf("Child process with pid %d exited\n", getpid());
          exit(t);
          return t;
        }
      }

      else {
        printf("Child process with pid: %d\n", getpid());
        srand(time(NULL));
        t = (rand() % 16) + 5;
        sleep(t);
        printf("Child process with pid %d exited\n", getpid());
        exit(t);
        return t;
      }

    return 0;
}
