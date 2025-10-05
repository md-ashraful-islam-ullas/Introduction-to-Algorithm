# include <bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    if (n == 1) return 1;
    int fact = factorial(n-1);
    return fact * n;
}
int main()
{
    cout << factorial(6) << endl;
    return 0; 
}