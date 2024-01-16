#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char* argv[]){
  if(argc != 2){
    printf(1, "One arg required!\n");
    exit();
  }
  int n_proc = atoi(argv[1]);
  printf(1, "Testing priority scheduler...\n");
  int pid;
  for (int i = 0; i < n_proc; i++) {
    pid = fork();
    if (pid < 0) {
      printf(1, "Fork failed\n");
      exit();
    } else if (pid == 0) {
      set_priority(getpid(), i+1);
      printptable();
      int j = 0;
      while (j < 100000000) {
        j++;
      }
      
      exit();
    }
  }
  for (int i = 0; i < n_proc; i++) {
    int pid = wait();
    printf(1, "Child process with pid %d exited\n", pid);
  }

  printf(1, "Priority scheduler test complete\n");

  exit();
}