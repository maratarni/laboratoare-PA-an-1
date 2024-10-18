#include <stdio.h>

int main()
{
    int n, ok = 0, i, j, numar_introdus, v[100];

    printf("care este lungimea vectorului? \n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    int decizie = 1;

    while (decizie == 1)
    {
        printf("ce numar vreti sa aflati daca poate fi descompus ca suma de doua elemente din vector? \n");
        scanf("%d", &numar_introdus);

        for (i = 0; i < n - 1; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (v[i] + v[j] == numar_introdus)
                {
                    printf("\nnumarul %d si numarul %d au suma egala cu %d", v[i], v[j], numar_introdus);
                    ok = 1;
                }
            }
            
        }

        if (ok == 0)
        {
             printf("nu exista pereche a caror suma este %d", numar_introdus);
        }

        printf("\ndoriti sa mai cautati alt numar?introduceti 1 pentru da si 0 pentru nu ");
        scanf("%d", &decizie);
        
    }
    return 0;
}