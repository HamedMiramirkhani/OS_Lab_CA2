#include "types.h"
#include "stat.h"
#include "user.h"

void 
print_curr_info(char* name, int curr_pid, int flag)
{
  if(flag)
  {
    printf(1, name);
    printf(1, " = %d\n", curr_pid);
  }
  printf(1,"current info: \n");
  printf(1,"~~ current PID = %d\n", getpid());
  printf(1, "~~ alive_children_count[%d] = %d \n", \
  getpid(), get_alive_children_count(getpid()));
  printf(1, "=======================================\n");
}

int
main(int argc, char *argv[])
{
	printf(1, "test of <<kill_first_child_process>> syscall\n\n");

  int parent_PID = getpid();
  print_curr_info("Parent", parent_PID, 1);
  printf(1, "call A=fork()\n");
  int A = fork();
  if(A) // if A = 0 => getpid() = child but if A > 0 => getpid() = parent
  {
    sleep(10);
    print_curr_info("A", A, 1);
    printf(1, "call B=fork()\n");
    int B = fork();
    if(B)
    {
      sleep(10);
      print_curr_info("B", B, 1);
      printf(1, "call C=fork()\n");
      int C = fork();
      if (C)
      {
        sleep(10);
        print_curr_info("C", C, 1);
        printf(1, "parent(PID = %d)'s children count = %d\n",
        parent_PID, get_alive_children_count(parent_PID));          
        printf(1, "call kill_first_alive_child_process(%d)\n", parent_PID);
        kill_first_child_process(parent_PID);
        printf(1, "parent(PID = %d)'s children count = %d\n",
        parent_PID, get_alive_children_count(parent_PID));
        print_curr_info("C", C, 0);
      }
    }
  }
  while (wait() != -1);
  exit();
}

