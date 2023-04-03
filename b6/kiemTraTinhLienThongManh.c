#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int n;
int G[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int order[MAX_NODES];
int count;

void dfs1(int u)
{
    visited[u] = 1;
    for (int v = 0; v < n; v++)
    {
        if (G[u][v] && !visited[v])
        {
            dfs1(v);
        }
    }
    order[count++] = u;
}

void dfs2(int u)
{
    visited[u] = 1;
    for (int v = 0; v < n; v++)
    {
        if (G[v][u] && !visited[v])
        {
            dfs2(v);
        }
    }
}

int is_strongly_connected()
{
    count = 0;
    for (int u = 0; u < n; u++)
    {
        visited[u] = 0;
    }
    for (int u = 0; u < n; u++)
    {
        if (!visited[u])
        {
            dfs1(u);
        }
    }

    for (int u = 0; u < n; u++)
    {
        visited[u] = 0;
    }
    int scc_count = 0;
    for (int i = count - 1; i >= 0; i--)
    {
        int u = order[i];
        if (!visited[u])
        {
            dfs2(u);
            scc_count++;
        }
    }
    return (scc_count == 1);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                scanf("%d", &G[u][v]);
            }
        }

        if (is_strongly_connected())
        {
            printf("Strongly Connected\n");
        }
        else
        {
            printf("Not connected\n");
        }
    }
    return 0;
}