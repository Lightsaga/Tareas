#include <stdio.h>
#include <stdlib.h>

typedef struct _block
{
    char value;
    char status;
}block;

static block memory[1000];
void* MiMalloc(size_t st)
{
    void* pointer;
    int aux=0;
    char v = 'f';
    int n=0;
    int i;
    for(i=0;i<sizeof(memory);i++)
    {
        if(memory[i].status==0x0&&v=='f')
        {
            pointer =&memory[i];
            n=i;
            v='t';
            aux++;
        }
        else if(memory[i].status!=0x0&&v=='t')
        {
            pointer =0x0;
            v='f';
            aux=0;
        }
        else if(memory[i].status==0x0&&v=='t')
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
                    memory[n].status='e';
                }
                else if(memory[n].status!='e')
                {
                    memory[n].status='f';
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
        *ptr2=0x0;
        ptr2++;
    }
    *ptr2=0x0;
}

int main()
{
    printf("Hello world!\n");
    void* ptra = (MiMalloc(10));
    void* ptrb = (MiMalloc(5));
    void* ptrc = (MiMalloc(15));
    MiFree(ptrb);
    void* ptrd = (MiMalloc(3));
    printf("Punteros:\n");
    int a = (unsigned) ptra;
    int b = (unsigned) ptrb;
    int c = (unsigned) ptrc;
    int d = (unsigned) ptrd;
    printf("%u\n",a);
    printf("%u\n",b);
    printf("%u\n",c);
    printf("%u\n",d);
    return 0;
}


