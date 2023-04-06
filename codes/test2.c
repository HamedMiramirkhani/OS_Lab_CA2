#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
	printf(1, "get_alive_children_count test\n\n");
  int cur_pid = getpid();
  printf(1,"getpid() = %d\n", cur_pid);
  printf(1, "alive_children_count[%d] = %d \n", cur_pid, get_alive_children_count(cur_pid));
  printf(1, "=======================================\n");

  printf(1, "now call A=fork()\n");
  int A = fork();
  if (A < 0)
  {
    printf(1,"Error in fork()\n");
    while (wait() != -1);
    exit();
  }
  else if(A) // اگر ==۰ را بذاریم میریم داخل فرزند اما اگه بزرگ تر ۰ باشه خیر
  {
    printf(1,"A = %d\n", A);
    int cur_pid = getpid();
    printf(1,"getpid() = %d\n", cur_pid);
    printf(1, "alive_children_count[%d] = %d \n", cur_pid, get_alive_children_count(cur_pid));
    printf(1, "=======================================\n");
    printf(1, "now call B=fork()\n");
    int B = fork();
    if (B)
    {
      printf(1,"B = %d\n", B);
      int cur_pid = getpid();
      printf(1,"getpid() = %d\n", cur_pid);
      printf(1, "alive_children_count[%d] = %d \n", cur_pid, get_alive_children_count(cur_pid));
      printf(1, "=======================================\n");
      printf(1, "now call C=fork()\n");
      int C = fork();
      if (C)
      {
        printf(1,"C = %d\n", C);
        int cur_pid = getpid();
        printf(1,"getpid() = %d\n", cur_pid);
        printf(1, "alive_children_count[%d] = %d \n", cur_pid, get_alive_children_count(cur_pid));
        printf(1, "=======================================\n");
      }
    }
  }
  while (wait() != -1);
  exit();
}

// int main()
// {
// 	if(fork() == 0) // child
// 	{
// 		if(fork())
// 		{
// 		}
// 		else
// 		{
// 			sleep(100);
// 			exit();
// 		}
		
// 	}
// 	else
// 	{
// 		if(fork() != 0) // parent
// 		{
// 		}
// 	}
// 	wait();
// 	exit();
// }

