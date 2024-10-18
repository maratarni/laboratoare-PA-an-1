#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// creare lista
struct nod
{
    int numar;
    struct nod *next;
};

// simpla inlantuita
typedef struct nod NOD;

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

void sort(NOD *head, int lungime)
{
    int i, j, numar_ales;
    NOD *urmator;
    NOD *curent;

    // k = lungime;
    for (i = 0; i < lungime - 1; i++)
    {
        curent = head;
        urmator = head->next;
        for (j = 0; j < lungime - i - 1; j++)
        {
            if (curent->numar > urmator->numar)
            {
                numar_ales = curent->numar;
                curent->numar = urmator->numar;
                urmator->numar = numar_ales;
            }
            curent = curent->next;
            urmator = urmator->next;
        }
    } // 1 2 3
} //      i=1  j=0

void stergere(int val, NOD **head)
{
    NOD *curent = *head;
    NOD *ant = NULL;

    if (curent == NULL)
    {
        printf("Nu exista");
        exit(1);
    }

    while (curent != NULL && curent->numar != val)
    {
        ant = curent;
        curent = curent->next;
    }

    if (curent != NULL && curent == *head)
    {
        *head = curent->next;
        free(curent);
        return;
    }

    if (curent != NULL)
    {
        ant->next = curent->next;
        free(curent);
    }
}
int main()
{
    int lungime, i;
    NOD *head = NULL;
    // k este lungimea listei
    printf("Care este lungimea listei?");
    scanf("%d", &lungime);
    for (i = 0; i < lungime; i++)
    {
        int nr;
        scanf("%d", &nr);
        inserare(&head, nr);
    }
    afisare(head);
    // sortare
    sort(head, lungime);
    afisare(head);
    // parcurg lista

    int ok;
    NOD *curent = head;

    while (curent != NULL && curent->next != NULL)
    {
        if (curent->numar == curent->next->numar)
        {
            int aux = curent->numar;
            curent = curent->next;
            stergere(aux, &head);
        }
        else
            curent = curent->next;
    }
    afisare(head);
    return 0;
}
// 1 2 4
