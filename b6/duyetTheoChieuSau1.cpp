#include <iostream>

using namespace std;

void dfs(int visited[], int index, int **arr, int n)
{
    visited[index] = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[index][i] == 1 && index != i && visited[i] == 0)
        {
            dfs(visited, i, arr, n);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int n;
        cin >> n;
        int **arr = new int *[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            int visited[n], first = 1;
            for (int j = 0; j < n; j++)
            {
                visited[j] = 0;
            }
            dfs(visited, i, arr, n);
            printf("From%4d can visit: ", i);
            for (int j = 0; j < n; j++)
            {
                if (j != i && visited[j] == 1)
                {
                    if (first == 1)
                    {
                        first = 0;
                    }
                    else
                    {
                        printf(",");
                    }
                    printf("%3d", j);
                }
            }
            if (first == 1)
            {
                cout << "No vertex";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}