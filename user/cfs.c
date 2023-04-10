#include "kernel/types.h"
#include "user/user.h"

int fib(int n)
{
  if (n <= 1)
  {
    return n;
  }

  return fib(n - 1) + fib(n - 2);


}

int main(int argc, char **argv)
{

  printf("PID\tPS_PRIORITY\tCFS_PRIORITY\tRTIME\tSTIME\tRETIME\n");
  if (fork() == 0)
  {
    if (fork() == 0)
    {
      set_ps_priority(10);
      set_cfs_priority(2);
    }
    else
    {
      set_ps_priority(1);
      set_cfs_priority(0);
    }
  }

  // cfs priorities: parent 1, child 0, grandchild 2

  // int i;
  // for (i = 0; i < 10000; i++)
  // {
  //   if (i % 1000 == 0)
  //   {
  //       // write(1, "going to sleep\n", 15);
  //       sleep(10);
  //       // write(1, "woke up\n", 8);
  //   }
  // }

  fib(45);
  wait(0, 0);
  wait(0, 0);

  int pid = getpid();
  int ps_priority = get_ps_priority(pid);
  int cfs_priority, rtime, stime, retime;

  if (get_cfs_stats(pid, &cfs_priority, &rtime, &stime, &retime))
  {
    fprintf(2, "error in get_cfs_stats system call\n");
    exit(1, "");
  }
  
  fprintf(1,"%d\t%d\t\t%d\t\t%d\t\t%d\n", pid, ps_priority, cfs_priority, rtime, stime, retime);
  exit(0, "");
}
