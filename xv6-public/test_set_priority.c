#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  int pid , priority;
  if(argc < 3){
    printf(1,"Invalid Input \n");
    exit();
  }
  pid = atoi(argv[1]);
  priority = atoi(argv[2]);
  printf(1,"pid %d \n ",pid);
  printf(1,"priority %d \n ",priority);
  
  int old = set_priority(pid,priority);

  printf(1,"Old Value is %d \n ",old);
  exit();
}