#include <stdio.h>
typedef struct 
{
   char nume[100];
   float timp;
}alergatori;

int main()
{
    alergatori a[10];
    int i, j;
    for(i=0; i<10; i++)
    {  
        gets(a[i].nume);
        scanf("%f", &a[i].timp);
        getchar();
    }
    for(i = 0; i < 9; i++)
    {
        for(j = i+1; j < 10; j++)
        {
            if(a[i].timp > a[j].timp)
            {
                alergatori aux;
                aux = a[i];
                a[i]= a[j];
                a[j]= aux;
            }
        }
    }
    for(i = 0; i < 10; i++)
    { 
        printf("alergatorul cu numele %s este pe locul %d ", a[i].nume, i+1);
        printf("\n");
    }
    return 0;
}