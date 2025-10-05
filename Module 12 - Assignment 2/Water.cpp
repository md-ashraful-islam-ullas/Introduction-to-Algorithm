#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<long long int, long long int>> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first;
            v[i].second = i;
        }
        sort(v.begin(), v.end(), greater<pair<long long int, long long int>>());
        
        int left = min(v[0].second, v[1].second);
        int right = max(v[0].second, v[1].second);
        cout << left << " " << right << endl;
    }
    return 0;
}