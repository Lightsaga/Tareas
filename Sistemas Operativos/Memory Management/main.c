#include <stdio.h>
#include <stdlib.h>

static char memory[1000];
static char memorystatus[1000];
void* FirstFit(size_t st)
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

void* NextFit(size_t st)
{
    void* pointer;
    int aux=0;
    char v = 'f';
    static int e = 0;
    int n=0;
    int i;
    for(i=e;i<sizeof(memory);i++)
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
    if(pointer != 0x0)
    {
     e=n;
    }
    return pointer;
}

void* BestFit(size_t st)
{
    void* pointer;
    void* BestPointer;
    int Baux=0;
    int Bi=0;
    int com = 0;
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
            if(Baux==0||Baux>aux)
            {
                Bi=i;
                BestPointer = pointer;
                Baux = aux;
            }
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
            com=1;
        }
    }
    if(com==0)
    {
        BestPointer=0x0;
    }
    else
    {
    n=Bi;
    for(;n<st;n++)
    {
        if(n==st-1)
        {
            memorystatus[n]='e';
        }
        else if(memorystatus[n]!='e')
        {
            memorystatus[n]='f';
        }
    }
    }
    return BestPointer;
}

void* WorstFit(size_t st)
{
    void* pointer;
    void* WorstPointer;
    int Waux=0;
    int Wi=0;
    int com = 0;
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
            if(Waux==0)
            {
                Wi=i;
                WorstPointer = pointer;
                Waux = aux;
            }
        }
        else if(memorystatus[i]!='t'&&v=='t')
        {
            if(Waux==0||Waux<aux)
            {
                Wi=i;
                WorstPointer = pointer;
                Waux = aux;
            }
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
            com=1;
        }
    }
    if(com==0)
    {
        WorstPointer=0x0;
    }
    else
    {
    n=Wi;
    for(;n<st;n++)
    {
        if(n==st-1)
        {
            memorystatus[n]='e';
        }
        else if(memorystatus[n]!='e')
        {
            memorystatus[n]='f';
        }
    }
    }
    return WorstPointer;
}

void* QuickFit(size_t st)
{
    void* pointer;
    int aux=0;
    char v = 'f';
    static int e =0;
    static int e1=0;
    static int e2=300;
    static int e3=600;
    int n=0;
    int i;

    if((st+1)<200)
    {
        e=e1;
    }
    if((st+1)<400&&(st+1)>200)
    {
        e=e2;
    }
    if((st+1)>400)
    {
        e=e3;
    }
    for(i=e;i<sizeof(memory);i++)
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
    if(pointer != 0x0)
    {
     e=n;
    }
    if((st+1)<200)
    {
        e1=e;
    }
    if((st+1)<400&&(st+1)>200)
    {
        e2=e;
    }
    if((st+1)>400)
    {
        e3=e;
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
    char c ='4';
    if(c=='1')
    {
    memset(memorystatus,'t',1000);
    printf("Hello world!\n");
    printf("Memoria Vacia\n");
    puts(memorystatus);
    void* ptra = (FirstFit(5));
    //MiFree(ptra);
    void* ptrb = (FirstFit(10));
    void* ptrc = (FirstFit(15));
    printf("Memoria con memoria asignada\n");
    puts(memorystatus);
    printf("Punteros\n");
    int a = (unsigned) ptra;
    int b = (unsigned) ptrb;
    int c = (unsigned) ptrc;
    printf("%u\n",a);
    printf("%u\n",b);
    printf("%u\n",c);
    }
    if(c=='2')
    {
    memset(memorystatus,'t',1000);
    printf("Hello world!\n");
    printf("Memoria Vacia\n");
    puts(memorystatus);
    void* ptra = (NextFit(5));
    MiFree(ptra);
    void* ptrb = (NextFit(3));
    void* ptrc = (NextFit(15));
    printf("Memoria con memoria asignada\n");
    puts(memorystatus);
    printf("Punteros\n");
    int a = (unsigned) ptra;
    int b = (unsigned) ptrb;
    int c = (unsigned) ptrc;
    printf("%u\n",a);
    printf("%u\n",b);
    printf("%u\n",c);
    }
    if(c=='3')
    {
    memset(memorystatus,'t',1000);
    printf("Hello world!\n");
    printf("Memoria Vacia\n");
    puts(memorystatus);
    void* ptra = (BestFit(5));
    MiFree(ptra);
    void* ptrb = (BestFit(10));
    void* ptrc = (BestFit(15));
    printf("Memoria con memoria asignada\n");
    puts(memorystatus);
    printf("Punteros\n");
    int a = (unsigned) ptra;
    int b = (unsigned) ptrb;
    int c = (unsigned) ptrc;
    printf("%u\n",a);
    printf("%u\n",b);
    printf("%u\n",c);
    }
    if(c=='4')
    {
    memset(memorystatus,'t',1000);
    printf("Hello world!\n");
    printf("Memoria Vacia\n");
    puts(memorystatus);
    void* ptra = (WorstFit(10));
    //MiFree(ptra);
    void* ptrb = (WorstFit(5));
   // MiFree(ptrb);
    void* ptrc = (WorstFit(15));
    printf("Memoria con memoria asignada\n");
    puts(memorystatus);
    printf("Punteros\n");
    int a = (unsigned) ptra;
    int b = (unsigned) ptrb;
    int c = (unsigned) ptrc;
    printf("%u\n",a);
    printf("%u\n",b);
    printf("%u\n",c);
    }
    return 0;
}


