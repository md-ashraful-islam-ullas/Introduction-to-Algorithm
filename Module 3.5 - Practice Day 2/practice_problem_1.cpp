# include <bits/stdc++.h>
using namespace std;
vector <int> adj_list[105];
bool vis[105];
int cnt = 0;

void dfs(int src)
{
    cnt++;
    vis[src] = true;
    for (int child : adj_list[src])
    {
        if (vis[child] == false)
        {
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));

    int x;
    cin >> x;
    dfs(x);
    cout << cnt << endl;
    return 0; 
}