#include <stdio.h>

#define MAX_N 100

int n;
int a[MAX_N][MAX_N];
int visited[MAX_N];

void dfs(int u)
{
    visited[u] = 1;
    
    for (int v = 0; v < n; v++)
    {
        if (a[u][v] && !visited[v])
        {
            dfs(v);
        }
    }
}

int is_connected()
{
    for (int u = 0; u < n; u++)
    {
        visited[u] = 0;
    }
    dfs(0);
    for (int u = 0; u < n; u++)
    {
        if (!visited[u])
        {
            return 0;
        }
    }
    return 1;
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
        if (is_connected())
        {
            printf("Connected\n");
        }
        else
        {
            printf("Not connected\n");
        }
    }
    return 0;
}
