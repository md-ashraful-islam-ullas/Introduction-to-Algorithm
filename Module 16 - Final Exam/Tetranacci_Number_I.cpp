# include <bits/stdc++.h>
using namespace std;
int dp[1005];
int fibonacci(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (n == 3) return 2;
    if (dp[n] != -1) return dp[n];
    dp[n] = fibonacci(n-1) + fibonacci(n-2) + fibonacci(n-3) + fibonacci(n-4);
    return dp[n];
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    cout << fibonacci(n);
    return 0; 
}