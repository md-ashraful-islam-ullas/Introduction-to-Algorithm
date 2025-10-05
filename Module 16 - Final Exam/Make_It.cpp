# include <bits/stdc++.h>
using namespace std;
int dp[100005]; 

bool make_it(long long int num, long long int x)
{
    if (num > x) return false;
    if (num == x) return true;
    if (dp[num] != -1) return dp[num];
    dp[num] = make_it(num + 3, x) || make_it(num*2, x);
    return dp[num];
}

int main()
{
    long long int t; cin >> t;
    while(t--)
    {
        long long int x; cin >> x;
        memset(dp, -1, sizeof(dp));
        if (make_it(1, x) == true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0; 
}