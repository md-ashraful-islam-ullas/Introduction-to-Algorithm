# include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e; cin >> n >> e;
    vector <int> adj_list[n];
    while (e--)
    {
        int a, b; cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    
    int q; cin >> q;
    while (q--)
    {
        vector <int> answer;
        int x; cin >> x;
        for (int i = 0; i < adj_list[x].size(); i++)
        {
            answer.push_back(adj_list[x][i]);
        }
        sort(answer.begin(), answer.end(), greater<int>());

        if (answer.empty() == true) cout << -1 << endl;
        else 
        {
            for (int j = 0; j < answer.size(); j++) cout << answer[j] << " ";
            cout << endl;
        }
    }
    return 0; 
}