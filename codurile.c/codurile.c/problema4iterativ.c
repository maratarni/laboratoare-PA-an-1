#include <stdio.h>
#include <stdlib.h>
struct nod
{
    int numar;
    struct nod *next;
};
 typedef struct nod NOD;
// afisare
void afisare(NOD *head)
{
    NOD *ceva;
    ceva = head;
    while (ceva != NULL)
    {
        printf("%d ", ceva->numar);
        ceva = ceva->next;
    }
    printf("\n");
}

// inserare
void inserare(NOD **head, int numar)
{
    NOD *nou = (NOD *)malloc(sizeof(NOD));
    if (nou == NULL)
    {
        printf("alocare dinamica esuata");
        exit(1);
    }
    nou->numar = numar;
    nou->next = (*head);
    (*head) = nou;
}

// Algoritm reverse ptr lista simplu inlantuita
void reverse(NOD **head)
{
    NOD *prev = NULL;
    NOD *curent = (*head);
    NOD *next;
    while (curent != NULL)
    {
        next = curent->next;
        curent->next = prev;
        prev = curent;
        curent = next;
    }
    (*head) = prev;
}
int main()
{
    NOD *head = NULL;
    int i, lungime;
    printf("care e lungimea?\n");
    scanf("%d", &lungime);
    printf("introduceti lista\n");
    for(i=0; i<lungime; i++)
    {
        int nr;
        scanf("%d", &nr);
        inserare(&head, nr);
    }
    printf("asa arata lista initiala:\n");
    afisare(head);
    reverse(&head);
    printf("asa arata lista inversata:\n");
    afisare(head);
    return 0;
}
