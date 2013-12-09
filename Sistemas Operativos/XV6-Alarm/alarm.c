#include "types.h"
#include "stat.h"
#include "user.h"

void prueba()
{	
	printf(1,"Hola soy la prueba\n");
}
void pruebaM()
{	
	printf(1,"Hola soy la pruebaM\n");
}

void pruebaS()
{	
	printf(1,"Hola soy la pruebaS\n");
}

void pruebaR()
{	
	printf(1,"Hola soy la pruebaR\n");
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
            alarm(X,&prueba);
   	    while(1){}
	}
    else
	{
	    printf(1," Error en Argumentos\n");
	}

  exit();
}


