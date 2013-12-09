#include "types.h"
#include "x86.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int ticksG;
int PID;

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;
  
  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;
  
  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_alarm(void)
{
/*PID = fork();
if(PID > 0)
{
cprintf("PID: %d\n", PID);
cprintf("\nSoy el padre\n");
PID=wait();
}
else if(PID == 0)
{
cprintf("PID: %d\n", PID);
cprintf("\nSoy el hijo\n");
exit();
}*/
  int ticks;
  void (*handler)();
 /* cprintf("funciona\n");
  //cprintf("%d\n",ticksG);
  cprintf("%d\n",handler);
  cprintf("%d\n",ticks);*/
  //cprintf("%d\n",&sys_getpid);	
  if(argint(0, &ticks) < 0)
      return -1;
  if(argptr(1, (char**)&handler, 1) < 0)
      return -1;
  proc->alarmticks = ticks;
  proc->alarmhandler = handler;
  //cprintf("%d\n",proc->pid);
  //proc->ticksInicio = ticksG;
      return 0;
}
