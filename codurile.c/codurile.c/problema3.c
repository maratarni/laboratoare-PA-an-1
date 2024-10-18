#include <stdio.h>
#include <stdlib.h>
// creem lista dubla inlantuita
struct nod
{
    int numar;
    struct nod *next;
    struct nod *prev;
};

typedef struct nod NOD;

int isEmpty(NOD *head)
{
    return head == NULL;
}
// inseram in lista noduri la inceput
void inserare(NOD **head, NOD *last, int numar)
{
    NOD *nou;
    nou = (NOD *)malloc(sizeof(NOD));
    if (nou == NULL)
    {
        printf("nu s a putut face alocarea dinamica");
        exit(1);
    }

    nou->numar = numar;

    if (isEmpty(*head))
        last = nou;
    else
        (*head)->prev = nou;

    nou->next = (*head);
    (*head) = nou;
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
void stergere(NOD *head, NOD *last, int lungime)
{
    NOD *curent = head;
    last = NULL;
    int i = 0;
    while (curent != NULL && i != lungime)
    {
        last = curent;
        curent = curent->next;
        i++;
    }
    if (curent == head)
        head = head->next;
    if (curent = last)
        last = curent->prev;
    if (curent != head && curent != last)
        curent->prev->next = curent->next;
    curent->next->prev = curent->prev;
}
int main()
{
    NOD *head = NULL;
    NOD *last = NULL;
    int lungime, i;
    printf("Care este lungimea listei?");
    scanf("%d", &lungime);
    for (i = 0; i < lungime; i++)
    {
        int nr;
        scanf("%d", &nr);
        inserare(&head, last, nr);
    }
    if (lungime % 2 == 0)
        lungime = lungime / 2;
    else
        lungime = lungime / 2 + 1;
    afisare(head);
    stergere(head,last,lungime);
    afisare(head);
    return 0;
}
