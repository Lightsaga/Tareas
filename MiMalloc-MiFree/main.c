#include <stdio.h>
#include <stdlib.h>

static char memory[1000];
static char memorystatus[1000];
void* MiMalloc(size_t st)
{
    void* pointer;
    int aux=0;
    char v = 'f';
    int n=0;
    int i;
    for(i=0;i<sizeof(memory);i++)
    {
        if(memorystatus[i]=='t'&&v=='f')
        {
            pointer =&memory[i];
            n=i;
            v='t';
            aux++;
        }
        else if(memorystatus[i]!='t'&&v=='t')
        {
            pointer =0x0;
            v='f';
            aux=0;
        }
        else if(memorystatus[i]=='t'&&v=='t')
        {
            aux++;
        }
        if(aux==(st+1))
        {
            n=i-aux;
            for(;n<i;n++)
            {
                if(n==i-1)
                {
                    memorystatus[n]='e';
                }
                else if(memorystatus[n]!='e')
                {
                    memorystatus[n]='f';
                }

            }
            break;
        }
    }
    return pointer;
}

void MiFree(void* ptr)
{
    char* ptr2 = (char*) ptr;
    while(*ptr2!='e')
    {
        *ptr2='t';
        ptr2++;
    }
    *ptr2='t';
}

int main()
{
    memset(memorystatus,'t',100);
    printf("Hello world!\n");
    printf("Memoria Vacia\n");
    puts(memorystatus);
    void* ptra = (MiMalloc(5));
    //MiFree(ptra);
    void* ptrb = (MiMalloc(10));
    void* ptrc = (MiMalloc(15));
    printf("Memoria con memoria asignada\n");
    puts(memorystatus);
    printf("Punteros\n");
    int a = (unsigned) ptra;
    int b = (unsigned) ptrb;
    int c = (unsigned) ptrc;
    printf("%u\n",a);
    printf("%u\n",b);
    printf("%u\n",c);

    return 0;
}


