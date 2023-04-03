#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXN 100

int n, m;
int a[MAXN][MAXN];
bool visited[MAXN];
int components[MAXN];
int componentSize;

void dfs(int u)
{
    visited[u] = true;
    components[componentSize++] = u;

    for (int v = 0; v < n; v++)
    {
        if (a[u][v] && !visited[v])
        {
            dfs(v);
        }
    }
}
void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}
void bfs(int u)
{
    int queue[MAXN];
    int front = 0, rear = -1;

    visited[u] = true;
    queue[++rear] = u;
    components[componentSize++] = u;

    while (front <= rear)
    {
        int v = queue[front++];

        for (int i = 0; i < n; i++)
        {
            if (a[v][i] && !visited[i])
            {
                visited[i] = true;
                queue[++rear] = i;
                components[componentSize++] = i;
            }
        }
    }
}

void findComponents()
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            componentSize = 0;
            // dfs(i);
            bfs(i);
            mergeSort(components, 0, componentSize - 1);
            for (int j = 0; j < componentSize; j++)
            {
                printf("%d ", components[j]);
            }
            printf("\n");
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }

        findComponents();

        printf("\n");
    }

    return 0;
}
