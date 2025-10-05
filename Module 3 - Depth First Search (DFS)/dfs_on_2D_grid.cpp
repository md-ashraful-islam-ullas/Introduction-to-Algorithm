# include <bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
int n, m;
vector <pair<int,int>> v = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m) return false;
    else return true;
}

void dfs(int si, int sj)
{
    cout << si << " " << sj << endl;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci, cj;
        ci = si + v[i].first;
        cj = sj + v[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false)
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    int a, b; cin >> a >> b;
    dfs(a, b);
    return 0; 
}