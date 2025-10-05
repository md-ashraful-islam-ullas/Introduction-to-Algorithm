#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int adj_mat[n+5][n+5];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = INT_MAX;
        }
    }

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = min(adj_mat[a][b], c);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj_mat[i][k] != INT_MAX && adj_mat[k][j]!= INT_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }

    int q; cin >> q;
    while (q--)
    {
        int src, destination; cin >> src >> destination;
        if (adj_mat[src][destination] == INT_MAX) cout << "-1" << endl;
        else cout << adj_mat[src][destination] << endl;
    }
    return 0;
}