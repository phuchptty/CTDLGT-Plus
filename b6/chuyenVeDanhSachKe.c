#include <stdio.h>
#include <stdlib.h>
#define x 100
void set(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
}

int main(void)
{
    int t;
    scanf("%d", &t);
    for (int k = 0; k < t; k++)
    {
        int n;
        scanf("%d", &n);
        int a1[x];
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
            int m = 0;
            set(a1, x);
            printf("Vertex%4d:", i);
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 1)
                {
                    a1[m] = j;
                    m++;
                }
            }
            for (int h = 0; h < m; h++)
            {
                if (h == m - 1)
                {
                    printf("%4d\n", a1[h]);
                }
                else
                {
                    printf("%4d,", a1[h]);
                }
            }
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
