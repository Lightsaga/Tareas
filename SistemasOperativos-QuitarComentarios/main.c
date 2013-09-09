#include <stdio.h>
#include <stdlib.h>


int main()
{

    FILE *fp;
    FILE *fp2;
    fp = fopen("test.txt","r");
    fp2 = fopen("test.txt","r");
    char a;
    char u;
    char x = 'f';
    char i;
    printf("Con comentarios:\n\n");
    while ((i = fgetc(fp2)) != EOF)
    {
        printf("%c",i);
    }
    fclose(fp2);
    printf("\n\n\nSin comentarios:\n");
    while ((u = fgetc(fp)) != EOF)
    {
        if(u=='/'&&x=='f'&&a!='/')
        {
            a=u;
        }
        else if(a=='/'&& u!='*'&& u!='/'&&x=='f')
        {
            printf("%c",a);
            printf("%c",u);
            a=' ';
        }
        else if(a=='/'&& (u=='*'||u=='/')&&x=='f')
        {
            if(u=='*')
            {
              x='t';
            }
            else
            {
               x='s';
            }
            a=' ';
        }
        else if(u=='*'&&x=='t')
        {
            a=u;
        }
        else if(u=='\n'&&x=='s')
        {
            x='f';
            a=' ';
        }
        else if(a=='*'&& u!='/'&&x=='t')
        {
            a=' ';
        }
        else if(a=='*'&& u=='/'&&x=='t')
        {
            x='f';
            a=' ';
        }
        else if(x!='t'&&x!='s')
        {
            printf("%c",u);
        }
    }
    fclose(fp);
    return 0;
}
