# include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int n, m;
vector <pair<int,int>> v = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m) return false;
    else return true;
}

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int sz = 1;
    for (int i = 0; i < 4; i++)
    {
        int ci, cj;
        ci = si + v[i].first;
        cj = sj + v[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false && grid[ci][cj] != '#') sz += dfs(ci, cj);
    }
    return sz;
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
    vector <int> number;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == false && grid[i][j] != '#')
            {
                int size = dfs(i, j);
                number.push_back(size);
            }
        }
    }
    if (number.empty() == true) cout << 0;
    else
    {
        sort(number.begin(), number.end());
        for (int i = 0; i < number.size(); i++) cout << number[i] << " ";
    }
    
    return 0; 
}