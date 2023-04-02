#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char **argv)
{
  int cfs_priority, rtime, stime, retime;

  if(argc < 2){
    fprintf(2, "usage: get_cfs_priority pid\n");
    exit(1, 0);
  }

  int pid = atoi(argv[1]);

  if (get_cfs_priority(pid, &cfs_priority, &rtime, &stime, &retime))
  {
    fprintf(2, "error in get_cfs_priority system call\n");
    exit(1, 0);
  }
  
  fprintf(1, "cfs_priority: %d rtime: %d stime: %d retime: %d\n", cfs_priority, rtime, stime, retime);
  exit(0, 0);
}
