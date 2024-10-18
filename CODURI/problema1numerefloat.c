#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// buble sort
void buble_sort(float v[], int lungime)
{
    int i, sortat;
    float aux;
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
void insertion_sort(float v[], int lungime)
{
    int i, j;
    float aux;
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
void selection_sort(float v[], int lungime)
{
    int i, j, poz;
    float aux;
    float min = v[0];
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
void merge_sort(float v[], int st, int dr)
{
    int i, j;
    float c[200];

    if (st < dr)
    {
        int m = (st + dr) / 2;

        merge_sort(v, st, m);
        merge_sort(v, m + 1, dr);

        i = st, j = m + 1;

        int k = 0;

        while (i <= m && j <= dr)
        {
            if (v[i] < v[j])
            {
                c[k++] = v[i++];
            }
            else
            {
                c[k++] = v[j++];
            }
        }

        while (i <= m)
            c[k++] = v[i++];

        while (j <= dr)
            c[k++] = v[j++];

        j = 0;

        for (i = st; i <= dr; i++)
        {
            v[i] = c[j++];
        }
    }
}

void quick_sort(float v[], int st, int dr)
{
    if (st < dr)
    {
        // pivotul este inițial v[st]
        int m = (st + dr) / 2;
        float aux = v[st];
        v[st] = v[m];
        v[m] = aux;
        int i = st, j = dr, d = 0;
        while (i < j)
        {
            if (v[i] > v[j])
            {
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

int main()
{
    int lungime, i;
    float v[100];
    int st, dr;
    st = 0;
    dr = lungime - 1;

    printf("care este lungimea dorita?");
    scanf("%d", &lungime);

    for (i = 0; i < lungime; i++)
    {
        scanf("%f", &v[i]);
    }

    printf("original:\n");

    for (i = 0; i < lungime; i++)
    {
        printf("%.2f ", v[i]);
    }

    //buble_sort(v,lungime);
    //insertion_sort(v, lungime);
    //selection_sort(v,lungime);
    //merge_sort(v, 0, lungime-1);
    quick_sort(v, 0, lungime-1);
    printf("\nsortat cu quick sort <3! :\n");
    for (i = 0; i < lungime; i++)
    {
        printf("%.2f ", v[i]);
    }
    return 0;
}