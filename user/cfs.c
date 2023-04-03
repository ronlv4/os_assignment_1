#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char **argv)
{
  int i;

  if (fork() == 0)
  {
    if (fork() == 0)
    {
        set_cfs_priority(2);
    }
    else
    {
        set_cfs_priority(0);
    }
  }
  // parent 1, child 0, grandchild 2

  for (i = 0; i < 3000; i++)
  {
    if (i % 1000 == 0)
    {
        // write(1, "going to sleep\n", 15);
        sleep(1);
        // write(1, "woke up\n", 8);
    }
  }

  int pid = getpid();
  int cfs_priority, rtime, stime, retime;

  printf("pid: %d\n");
  printf("cfs stats: \n");
  if (get_cfs_stats(pid, &cfs_priority, &rtime, &stime, &retime))
  {
    fprintf(2, "error in get_cfs_stats system call\n");
    exit(1, 0);
  }
  
  fprintf(1, "cfs_priority: %d rtime: %d stime: %d retime: %d\n", cfs_priority, rtime, stime, retime);
  exit(0, 0);
}
