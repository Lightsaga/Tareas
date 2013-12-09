#include "types.h"
#include "stat.h"
#include "user.h"


int getpid(void);

void prueba()
{	
	printf(1,"Hola soy la prueba\n");
	exit();
}
void pruebaM()
{	
	printf(1,"Hola soy la pruebaM\n");
	exit();
}

void GetPIDAlarm()
{	
	printf(1,"El PID del proceso es: %d\n",getpid());
	exit();
}

void pruebaR()
{	
	printf(1,"Hola soy la pruebaR\n");
	exit();
}


int main(int argc, char **argv)
{
    /*int X = (int)argv[1];
    alarm(X,&prueba);
    while(1){}*/
    /*alarm(300,&pruebaM);
    while(1){}
    alarm(100,&pruebaS);
    while(1){}
    alarm(100000,&pruebaR);
    while(1){}*/
    if(argc == 2)
	{	
	    int X = atoi(argv[1]);
	    //printf(1, "ls: directory:  %d\n", &prueba);
	    //printf(1,argv[1]);
            //alarm(X,(void (*)())argv[2]);
            alarm(X,&GetPIDAlarm);
   	    while(1){}
	}
    else
	{
	    printf(1," Error en Argumentos\n");
	}

  exit();
}


