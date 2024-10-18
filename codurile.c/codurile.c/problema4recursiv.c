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
NOD *head = NULL;
// Algoritm reverse ptr lista simplu inlantuita
void reverse(NOD* curent,NOD* prev)
{
    if (curent == NULL)
    {
        head = prev;
        return;
    }
    NOD* next = curent->next;
    curent->next = prev;
    reverse(next, curent);

}
int main()
{
    int i, lungime;
    printf("care e lungimea?\n");
    scanf("%d", &lungime);
    printf("introduceti lista\n");
    for (i = 0; i < lungime; i++)
    {
        int nr;
        scanf("%d", &nr);
        inserare(&head, nr);
    }
    printf("asa arata lista initiala:\n");
    afisare(head);
    reverse(head, NULL);
    printf("asa arata lista inversata:\n");
    afisare(head);
    return 0;
}
