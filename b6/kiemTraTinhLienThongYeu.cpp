#include <iostream>

using namespace std;

void dfs(int visited[], int index, int **arr, int n, int arrIndex[], int &indexStack)
{
    visited[index] = 1;
    arrIndex[indexStack++] = index;
    for (int i = 0; i < n; i++)
    {
        if (arr[index][i] == 1 && index != i && visited[i] == 0)
        {
            dfs(visited, i, arr, n, arrIndex, indexStack);
        }
    }
}

void dfs1(int visited[], int index, int **arr, int n)
{
    visited[index] = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[index][i] == 1 && index != i && visited[i] == 0)
        {
            dfs1(visited, i, arr, n);
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
        int **arrTG = new int *[n];
        int **arrVH = new int *[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[n];
            arrTG[i] = new int[n];
            arrVH[i] = new int[n];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
                arrVH[i][j] = arr[i][j];
                arrTG[j][i] = arr[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arrVH[i][j] == 1)
                {
                    arrVH[j][i] = 1;
                }
            }
        }
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << " " << arrVH[i][j] ;

        //     }
        //     cout << " VH" << endl;
        // }
        // cout << endl;
        int visited[n], arrIndex[n], indexStack = 0, count = 0;
        for (int j = 0; j < n; j++)
        {
            visited[j] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                count++;
                dfs1(visited, i, arrVH, n);
            }
        }

        if (count != 1)
        {
            cout << "Not Connected At All";
        }
        else
        {
            count = 0;
            for (int j = 0; j < n; j++)
            {
                visited[j] = 0;
            }
            dfs(visited, 0, arr, n, arrIndex, indexStack);
            if (indexStack != n)
            {
                cout << "Weakly Connected";
            }
            else
            {
                for (int j = 0; j < n; j++)
                {
                    visited[j] = 0;
                }
                for (int i = 0; i < n; i++)
                {
                    if (visited[i] == 0)
                    {
                        count++;
                        dfs1(visited, arrIndex[i], arrTG, n);
                    }
                }
                if (count == 1)
                {
                    cout << "Strongly Connected";
                }
                else
                {
                    cout << "Weakly Connected";
                }
            }
        }
        cout << endl;
    }
    return 0;
}