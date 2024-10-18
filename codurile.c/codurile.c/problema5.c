#include <stdio.h>
#include <stdlib.h>
struct nod
{
    int numar;
    struct nod *next;
};
typedef struct nod NOD;

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
void contopire(NOD **head1, NOD *head2)
{
    if(*head1==NULL)
    {
        (*head1)=head2;
        return;
    }
    NOD *curent;
    curent = (*head1);
    while (curent->next != NULL)
        curent = curent->next;
    curent->next=head2;
}
int main()
{
    NOD *head1 = NULL;
    NOD *head2 = NULL;
    int lungime1, lungime2, i, j;
    printf("care este lungimea primei liste?\n");
    scanf("%d", &lungime1);
    // introducerea listei 1
    for (i = 0; i < lungime1; i++)
    {
        int nr1;
        scanf("%d", &nr1);
        inserare(&head1, nr1);
    }

    printf("care este lungimea listei nr 2?\n");
    scanf("%d", &lungime2);

    // inserare lista nr 2
    for (j = 0; j < lungime2; j++)
    {
        int nr2;
        scanf("%d", &nr2);
        inserare(&head2, nr2);
    }
    printf("asta e prima\n");
    afisare(head1);
    printf("asta e a doua\n");
    afisare(head2);
    contopire(&head1, head2);
    printf("lista contopita\n");
    afisare(head1);
    return 0;
}