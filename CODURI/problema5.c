#include <stdio.h>
//sortare care are complexitatea cea mai buna O(k+n) si cea mai rea O(n*k), k=numarul de cifre a valorii maxime
//aici aflam maximul pentru a vedea de cate ori apelam subprogramul
int maxim(int a[], int n)//a vector, n lungimea vectorului
{
    int max = a[0];
    for(int i = 1; i < n; i++)
    {
        if(a[i] > max)
            max = a[i];
    }
    return max; //returnam maximul din tot vectorul
}

void countingSort(int a[], int n, int exp) // Definim funcția countingSort care sortează un vector de numere întregi 'a' cu lungimea 'n' și cu exponentul 'exp'
{
    int sortat[n]; // Declaram un vector 'output' pentru a stoca rezultatul final al sortării
    int cifre[10] = {0}; // Declaram un vector 'count' pentru a stoca frecvența fiecărei cifre

    // Calculăm frecvența fiecărei cifre
    for (int i = 0; i < n; i++)
        cifre[(a[i] / exp) % 10]++; // Calculăm frecvența cifrei curente și o stocăm în vectorul 'count'

    // Calculăm prefixele sumei pentru a stabili poziția fiecărui element în vectorul sortat
    for (int i = 1; i < 10; i++)
        cifre[i] += cifre[i - 1]; // Adăugăm frecvența cifrei anterioare pentru a obține prefixele sumei

    // Plasăm elementele în ordine sortată în vectorul de ieșire
    for (int i = n - 1; i >= 0; i--) // Parcurgem vectorul original de la sfârșit către început
    {
        sortat[cifre[(a[i] / exp) % 10] - 1] = a[i]; // Plasăm elementul curent în poziția corespunzătoare în vectorul de ieșire
        cifre[(a[i] / exp) % 10]--; // Scădem unu din frecvența cifrei curente pentru a actualiza poziția acesteia în viitor
    }

    // Copiem vectorul de ieșire în vectorul original pentru a actualiza ordinea elementelor
    for (int i = 0; i < n; i++)
        a[i] = sortat[i]; // Copiem elementele sortate din vectorul de ieșire în vectorul original 'a'
}

void radixsort(int a[], int n)//algoritmul recursiv radix :0
{

    // aflam maximul din vectorul dat
    int max = maxim(a, n);

    // aplicam counting sortul pentru exp = 1 care va creste de 10 ori pana ajunge la lungimea maximului gasit
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(a, n, exp);
}

// afisarea
void afisare(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

int main()
{
    //luam un exemplu
    int a[] = {181, 289, 390, 121, 145, 736, 514, 888, 122};
    int n = sizeof(a) / sizeof(a[0]);
    printf("inainte de sortare \n");
    afisare(a,n);
    //aplicam sortarea
    radixsort(a, n);
    printf("vectorul arata asa dupa sortare cu RADIXXXX: \n");
    afisare(a, n);
}

