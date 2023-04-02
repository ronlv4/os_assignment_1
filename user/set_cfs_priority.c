#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char **argv)
{
  if(argc < 2){
    fprintf(2, "usage: set_cfs_priority priority\n");
    exit(1, 0);
  }

  int priority = atoi(argv[1]);

  if (priority != 0 && priority != 1 && priority != 2)
  {
    printf("invalid priority, must be one of {0, 1, 2}\n");
    exit(1, 0);
  }

  if (set_cfs_priority(priority) < 0)
  {
    fprintf(2, "error in set_cfs_priority system call\n");
    exit(1, 0);
  }
  exit(0, 0);
}
