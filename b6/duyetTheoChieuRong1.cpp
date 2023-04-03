#include <iostream>
#include <queue>

using namespace std;

void bfs(int visited[], int index, int **arr, int n)
{
    queue<int> q;
    q.push(index);
    visited[index] = 1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            // Duyệt các đỉnh chưa được thăm. Nếu chưa có thì đẩy vào queue và set visited = true
            if (arr[v][i] == 1 && index != i && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    // So luong testcase
    int t;
    cin >> t;

    for (int k = 0; k < t; k++)
    {
        // Số đỉnh của đồ thị
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

            // Đánh đấu row đó là đã duyệt qua
            for (int j = 0; j < n; j++)
            {
                visited[j] = 0;
            }

            bfs(visited, i, arr, n);

            printf("From%4d can visit: ", i);

            for (int j = 0; j < n; j++)
            {
                // Nếu kết quả từ bfs trả về là true => có thể đi
                if (j != i && visited[j] == 1)
                {
                    // Nếu là số đầu thì không có dấu phẩy
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

            // Trường hợp không có cạnh nào liên kết
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