#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int MXN = 505;
int n, m;
void hanoi(int n, int a, int b, int c)
{ // n disks , move disk from a to c
    if (n == 1)
    {
        cout << a << " " << c << "\n";
        return;
    }
 
    hanoi(n - 1, a, c, b);
    hanoi(1, a, b, c);
    hanoi(n - 1, b, a, c);
}
void solve()
{
    cin >> n;
 
    cout << (1 << n) - 1 << "\n";
    hanoi(n, 1, 2, 3);
 
    return;
}
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
