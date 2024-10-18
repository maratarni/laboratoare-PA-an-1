#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// buble sort
void buble_sort(int v[], int lungime)
{
    int i, sortat, aux;
    do
    {
        sortat = 1;
        for (i = 0; i < lungime - 1; i++)
            if (v[i] > v[i + 1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                sortat = 0;
            }
    } while (sortat == 0);
}

// insertion sort
void insertion_sort(int v[], int lungime)
{
    int i, j, aux;
    for (i = 1; i < lungime; i++)
    {
        aux = v[i]; 
        j = i - 1;
        while (j >= 0 && v[j] > aux)
        {
            v[j + 1] = v[j];
            j--;
        }
      
        v[j + 1] = aux;
    }
}

//3 4 1 2 -> 3 4 4 2->3 3 4 2 -> 1 3 4 2
//selection sort
void selection_sort(int v[], int lungime)
{
    int i, j, poz, aux;
    int min = v[0];
    for (i = 0; i < lungime; i++)
    {
        min = v[i];
        for (j = i + 1; j < lungime; j++)
            if (v[j] < min)
            {
                min = v[j];
                poz = j;
            }
        if (v[i] > min)
        {
            aux = v[i];
            v[i] = v[poz];
            v[poz] = aux;
        }
    }
}
void merge_sort(long int v[], int st, int dr, long int c[]) {
    int i, j;

    if (st < dr) {
        int m = (st + dr) / 2;

        merge_sort(v, st, m, c);
        merge_sort(v, m + 1, dr, c);

        i = st, j = m + 1;

        int k = 0;

        while (i <= m && j <= dr) {
            if (v[i] < v[j]) {
                c[k++] = v[i++];
            } else {
                c[k++] = v[j++];
            }
        }

        while (i <= m)
            c[k++] = v[i++];

        while (j <= dr)
            c[k++] = v[j++];

        j = 0;

        for (i = st; i <= dr; i++) {
            v[i] = c[j++];
        }
    }
}

void quick_sort(int v[], int st, int dr) {
    if (st < dr) {
        // pivotul este inițial v[st]
        int m = (st + dr) / 2;
        int aux = v[st];
        v[st] = v[m];
        v[m] = aux;
        int i = st, j = dr, d = 0;
        while (i < j) {
            if (v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                d = 1 - d;
            }
            i += d;
            j -= 1 - d;
        }
        quick_sort(v, st, i - 1);
        quick_sort(v, i + 1, dr);
    }
}

int main() {
    int i;
    int v[100]; // Schimbăm dimensiunea vectorului la 60000
    int st;
    int dr;

    st = 0;
    dr = 9;

    for (i = 0; i < 10; i++) {
        v[i] = rand();
    }

    clock_t start, stop;
    float timp;

    start = clock();
    buble_sort(v,9); // Apelăm quick_sort în loc de merge_sort
    stop = clock();

    timp = (float)(stop - start) / CLOCKS_PER_SEC;

    printf("Timpul de rulare pentru buble este: %f", timp);

    return 0;
}

