#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char **argv)
{
  if(argc < 2){
    fprintf(2, "usage: set_policy sched_policy\n");
    exit(1, 0);
  }

  int policy = atoi(argv[1]);

  if (policy != 0 && policy != 1 && policy != 2)
  {
    fprintf(1, "invalid policy, must beone of {0, 1, 2}\n");
    exit(1, 0);
  }

  if (set_policy(policy) < 0)
  {
    fprintf(2, "error in set_policy system call\n");
    exit(1, 0);
  }

  exit(0, 0);
}
