#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int n, m, si, sj, di, dj;
vector <pair<int, int>> v = {{0,1},{0,-1},{-1,0},{1,0}}; // priority: right, left, up, down
bool flag = false;
pair<int, int> parent[1005][1005];

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m) return false;
    else return true;
}

void bfs(int si1, int sj1)
{
    queue<pair<int, int>> q;
    q.push({si1, sj1});
    vis[si1][sj1] = true;
    parent[si1][sj1] = {-1, -1};
    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        int x = front.first, y = front.second;
        if (x == di && y == dj)
        {
            flag = true;
            return;
        }
        for (auto dir : v)
        {
            int ci = x + dir.first;
            int cj = y + dir.second;
            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#')
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
                parent[ci][cj] = {x, y};
            }
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
            if (grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
            parent[i][j] = {-2, -2}; // Initialize to invalid
        }
    }
    memset(vis, false, sizeof(vis));
    bfs(si, sj);
    if (flag)
    {
        int curr_i = di, curr_j = dj;
        while (curr_i != si || curr_j != sj)
        {
            int prev_i = parent[curr_i][curr_j].first;
            int prev_j = parent[curr_i][curr_j].second;
            if (grid[curr_i][curr_j] != 'R' && grid[curr_i][curr_j] != 'D')
            {
                grid[curr_i][curr_j] = 'X';
            }
            curr_i = prev_i;
            curr_j = prev_j;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}