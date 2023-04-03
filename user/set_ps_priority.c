#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char **argv)
{
  if(argc < 2){
    fprintf(2, "usage: set_ps_priority priority\n");
    exit(1, "");
  }

  int priority = atoi(argv[1]);

  if (priority < 1 || priority > 10)
  {
    printf("invalid priority, must be between 1 to 10\n");
    exit(1, "");
  }

  if (set_ps_priority(priority) < 0)
  {
    fprintf(2, "error in set_ps_priority system call\n");
    exit(1, "");
  }

  exit(0, "");
}
