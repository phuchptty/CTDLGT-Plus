#include <stdio.h>
#include <stdlib.h>

void in(int **F, int n, int M, int A[], int C[])
{
    printf("   C   A i/v");
    for (int i = 0; i <= M; i++)
    {
        printf("%4d", i);
    }
    printf("\n");
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            printf("           0");
        }
        else
        {
            printf("%4d%4d%4d", C[i - 1], A[i - 1], i);
        }
        for (int j = 0; j <= M; j++)
        {
            printf("%4d", F[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, M;
    scanf("%d %d", &n, &M);
    int A[n], C[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &C[i]);
    }
    int **F = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i < n + 1; i++)
    {
        F[i] = (int *)malloc((M + 1) * sizeof(int));
    }
    // Tao bang phuong an
    for (int i = 0; i < M + 1; i++)
    {
        F[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int v = 0; v <= M; v++)
        {
            F[i][v] = F[i - 1][v];
            if (A[i - 1] <= v && F[i][v] < F[i - 1][v - A[i - 1]] + C[i - 1])
            {
                F[i][v] = F[i - 1][v - A[i - 1]] + C[i - 1];
            }
        }
    }
    in(F, n, M, A, C);
    printf("%d\n", F[n][M]);
    int v = M;
    int *vec = (int *)malloc(n * sizeof(int));
    int index = 0;
    for (int i = n; i > 0; i--)
    {
        if (F[i][v] != F[i - 1][v])
        {
            vec[index++] = i;
            v = v - A[i - 1];
        }
    }
    for (int i = index - 1; i >= 0; i--)
    {
        printf("%d(%d,%d) ", vec[i], A[vec[i] - 1], C[vec[i] - 1]);
    }

    for (int i = 0; i < n + 1; i++)
    {
        free(F[i]);
    }
}
