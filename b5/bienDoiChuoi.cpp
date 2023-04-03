#include <iostream>
#include <cstring>

using namespace std;

void in(int **f, int m, int n)
{
    cout << "   F";
    for (int i = 0; i <= n; i++)
    {
        printf("%4d", i);
    }
    cout << endl;
    for (int i = 0; i <= m; i++)
    {
        printf("%4d", i);
        for (int j = 0; j <= n; j++)
        {
            printf("%4d", f[i][j]);
        }
        cout << endl;
    }
}

int min3(int x, int y, int z)
{
    int tmp = x < y ? x : y;
    return z < tmp ? z : tmp;
}

int main()
{
    int m, n;
    cin >> m >> n;

    int **f = new int *[m + 1];

    for (int i = 0; i < m + 1; i++)
    {
        f[i] = new int[n + 1];
    }

    string X, Y;

    cin >> X >> Y;

    // Khoi Tao
    // Fill in the first row and column of the table with values 0 to m and 0 to n respectively
    for (int i = 0; i <= m; i++)
        f[i][0] = i;

    for (int j = 0; j <= n; j++)
        f[0][j] = j;
    
     // Compute the edit distance
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                f[i][j] = f[i - 1][j - 1]; // Characters match, no edit required
            }
            else
            {
                // Compute the minimum of three possible edit operations: insert, replace, or delete
                f[i][j] = min3(f[i][j - 1], f[i - 1][j - 1], f[i - 1][j]) + 1;
            }
        }
    }

    in(f, m, n);

    // Compute the edit sequence
    int count = 0; // Count the number of edit operations

    while (m >= -1 && n >= -1)
    {
        if (X[m - 1] == Y[n - 1])
        {
            m--; // Characters match, move to the next pair
            n--;
        }
        else
        {
            if (f[m][n] == f[m][n - 1] + 1) // Insert operation
            {
                if (n > 0)
                {
                    count++;
                }
                n--; // Move to the next character in Y
            }
            else if (f[m][n] == f[m - 1][n - 1] + 1) // Replace operation
            {
                if (n > 0 && m > 0) // neither string has reached its beginning
                {
                    count++;
                }
                m--; // Move to the previous character in X
                n--;
            }
            else // deletion operation
            {
                if (m > 0)  // the character to be deleted is not the first character
                {
                    count++;
                }
                m--;
            }
        }
    }

    cout << count << endl;

    // Backtracking to obtain the edit sequence
    m = X.length(), n = Y.length();

    while (m >= -1 && n >= -1)
    {
        // printf("(m, n):(%d, %d)\n", m, n);
        // If the current character of X and Y match, move to the previous characters
        if (X[m - 1] == Y[n - 1])
        {
            m--;
            n--;
        }
        else
        {
            // If the current character of X and Y do not match, there are three possible operations:
            if (f[m][n] == f[m][n - 1] + 1) // Insertion operation
            {
                if (n > 0)
                {
                    printf("Insert(%d,%c)\n", m, Y[n - 1]);
                }
                n--;
            }
            else if (f[m][n] == f[m - 1][n - 1] + 1) // Replacement operation
            {
                if (n > 0 && m > 0)
                {
                    printf("Replace(%d,%c)\n", m, Y[n - 1]);
                }
                m--;
                n--;
            }
            else // Deletion operation
            {
                if (m > 0)
                {
                    printf("Delete(%d)\n", m);
                }
                m--;
            }
        }
    }

    return 0;
}
