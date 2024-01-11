#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int MXN = 505;
 
void solve()
{
    int n, m;
    cin >> n >> m;
 
    int l = 2 * n - m;
    int r = 2 * m - n;
 
    if (l >= 0 && l % 3 == 0 && r >= 0 && r % 3 == 0)
    {
        cout << "YES"
             << "\n";
    }
    else
        cout << "NO"
             << "\n";
 
    return;
}
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
