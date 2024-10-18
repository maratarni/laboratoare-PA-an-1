#include <stdio.h>
#include <stdlib.h>
// algoritm de verificare ca este palindrom4
// incepem prin creare
struct nod
{
    int numar;
    struct nod *next;
};
typedef struct nod NOD;

// algortim de afisare
void afisare(NOD *head)
{
    NOD *ceva;
    ceva = head; // adresa
    while (ceva != NULL)
    {
        printf("%d ", ceva->numar);
        ceva = ceva->next;
    }
    printf("\n");
}

void inserare(NOD **head, int numar)
{
    NOD *plus = (NOD *)malloc(sizeof(NOD));
    if (plus == NULL)
    {
        printf("Nu se poate");
        exit(1);
    }
    plus->numar = numar;
    plus->next = *head;
    *head = plus;
}

// vreau sa creez un vector cu toate elem listei
void vector(NOD *head, int *v)
{
    NOD *ceva;
    ceva = head;
    int i = 0;
    while (ceva != NULL)
    {
        v[i++] = ceva->numar;
        ceva = ceva->next;
    }
}
int palindrom(int v[], int lungime)
{
    int i, ok = 1;
    for (i = 0; i < lungime/2; i++)
        if (v[i] != v[lungime - i - 1])
            ok = 0;

   return ok;
}
 int main()
{
    NOD *head = NULL;
    int i, lungime, v[100];

    printf("care este lungimea listei?");
    scanf("%d", &lungime);

    for (i = 0; i < lungime; i++)
    {
        int nr;
        scanf("%d", &nr);
        inserare(&head, nr);
    }
    printf("lista introdusa: ");
    afisare(head);

    vector(head, v);
   if (palindrom(v, lungime))
        printf("e palindrom");
    else
        printf("nu e palindrom");
    return 0;
}