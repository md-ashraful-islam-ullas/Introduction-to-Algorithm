# include <bits/stdc++.h>
using namespace std;
vector <int> adj_list[105];
bool vis[105];

int dfs (int src)
{
    vis[src] = true;
    int cnt = 1;
    for (int child : adj_list[src])
    {
        if (vis[child] == false)
        {
            cnt += dfs(child);
        }
    }
    return cnt;
}

int main()
{
    int n, e; cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    vector <int> components;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            int compSize = dfs(i);
            components.push_back(compSize);
        }
    }

    sort(components.begin(), components.end());
    for (int size : components) cout << size << " ";
    return 0; 
}