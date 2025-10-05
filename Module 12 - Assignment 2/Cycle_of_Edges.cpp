# include <bits/stdc++.h>
using namespace std;
int parent[100005];
int group_size[100005];

int find(int val)
{
    if (parent[val] == -1) return val;
    int leader = find(parent[val]);
    parent[val] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if (group_size[leader1] >= group_size[leader2])
    {
        parent[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else 
    {
        parent[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main()
{
    memset(parent, -1, sizeof(parent));
    memset(group_size, 1, sizeof(group_size));
    int n, e; cin >> n >> e;
    int cnt = 0;
    while (e--)
    {
        int a, b; cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);

        if (leaderA == leaderB) cnt++;
        else dsu_union(a,b);
    }
    cout << cnt << endl;
    return 0; 
}
