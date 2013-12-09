#include "types.h"
#include "stat.h"
#include "user.h"
#include "proc.h"
#include "traps.h"
#include "fs.h"

int
sys_alarm(void)
{
  int ticks;
  void (*handler)();
  if(argint(0, &ticks) < 0)
    return -1;
  if(argptr(1, (char**)&handler, 1) < 0)
    return -1;
  proc->alarmticks = ticks;
  proc->alarmhandler = handler;
    return 0;
}

int
main(int argc, char *argv[])
{
	if(argc == 3)
	{	
		printf(1,argv[1]);
		printf(1,argv[2]);
	}
    else
	{
		printf(1," Error en Argumentos\n");
	}

  exit();
}
