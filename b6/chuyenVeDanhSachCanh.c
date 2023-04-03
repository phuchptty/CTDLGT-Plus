#include <stdio.h>
#include <stdlib.h>
#define x 1000
void set(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int k = 0; k < t; k++)
    {
        int n;
        scanf("%d", &n);
        int a1[x], b1[x];
        set(a1, x);
        set(b1, x);
        int **a = (int **)malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++)
        {
            a[i] = (int *)malloc(n * sizeof(int));
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] != 0)
                {
                    a1[m] = i;
                    b1[m] = j;
                    m++;
                }
            }
        }
        for (int h = 0; h < m; h++)
        {
            if (h == m - 1)
            {
                printf("(%d, %d)", a1[h], b1[h]);
            }
            else
                printf("(%d, %d), ", a1[h], b1[h]);
        }
        printf("\n");

        for (int i = 0; i < n; i++)
        {
            free(a[i]);
        }

        free(a);
    }

    return 0;
}
