#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

uint64
sys_exit(void)
{
  int n;
  char msg[MAXEXIT];
  argint(0, &n);
  if (argstr(1, msg, MAXEXIT) < 0)
    return -1;
  if (*msg >= 0 && *msg < 33)
  {
    exit(n, "");
  }
  
  exit(n, msg);
  return 0;  // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  uint64 msg;
  argaddr(0, &p);
  argaddr(1, &msg);
  return wait(p, msg);
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(killed(myproc())){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

uint64 sys_memsize(void)
{
    return myproc()->sz;
}

uint64 sys_set_ps_priority(void)
{
  int priority;

  argint(0, &priority);

  return set_ps_priority(priority);
}
uint64 sys_get_ps_priority(void)
{
  int pid;

  argint(0, &pid);

  return get_ps_priority(pid);
}

uint64 sys_set_cfs_priority(void)
{
  int priority;

  argint(0, &priority);

  return set_cfs_priority(priority);
}

uint64 sys_get_cfs_stats(void)
{
  int pid;
  uint64 cfs_priority, rtime, stime, retime;

  argint(0, &pid);
  argaddr(1, &cfs_priority);
  argaddr(2, &rtime);
  argaddr(3, &stime);
  argaddr(4, &retime);

  return get_cfs_stats(pid, cfs_priority, rtime, stime, retime);
}



uint64 sys_set_policy(void)
{
  int policy;

  argint(0, &policy);

  return set_policy(policy);
}

uint64 sys_get_policy(void)
{
  return get_policy(); 
}