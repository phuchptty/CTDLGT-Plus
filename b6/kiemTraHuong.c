#include <stdio.h>

int main()
{
    int n, i, j;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int directed = 0;
        scanf("%d", &n);
        int graph[n][n];

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                scanf("%d", &graph[i][j]);
            }
        }

        // đồ thị có hướng tức là chỉ cần có hai đỉnh có hướng
        // tức là từ đỉnh A -> B được nhưng B -> A thì không được
        // -> xét mảng 2 chiều nếu A[i][j] và A[j][i] khác nhau thì tức là có hướng
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (graph[i][j] != graph[j][i])
                {
                    directed = 1;
                    break;
                }
            }
        }

        if (directed == 1)
        {
            printf("Directed graph\n");
        }
        else
        {
            printf("Undirected graph\n");
        }
    }
    return 0;
}
