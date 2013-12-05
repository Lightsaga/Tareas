#include <stdio.h>
#include <stdlib.h>

void fill_bitmaps(int* PtrI,char* PtrC, int Ci)
{
    int* ptrI =PtrI;
    char* ptrC = PtrC;
    int i=0;
    int j=0;
    while(j != Ci)
    {
        if(*ptrC !=0)
        {
            *ptrI = *ptrI | 0b10000000 >>i;
        }
        if(i==8)
        {
          ptrI++;
          i=0;
        }
        ptrC++;
        i++;
        j++;
    }
}

int main()
{
    int X = 16;
    char Memoria[16] = {'T','U','R','I',0,0,0,0,0,0,0,0,'B','I','T',0};
    int Bitmaps[2] = {0b00000000,0b00000000};
    fill_bitmaps(&Bitmaps,&Memoria,X);
    printf("%d\n",Bitmaps[0]);
    printf("%d",Bitmaps[1]);
    return 0;
}

