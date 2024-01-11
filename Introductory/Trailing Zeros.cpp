#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int MXN = 505;
 
int n;
void solve()
{
    cin >> n;
    int ans = 0;
    for (int i = 5; i <= n; i *= 5)
    {
        ans += n / i;
    }
    cout << ans << "\n";
}
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
 
    while (t--)
    {
        solve();
    }
    return 0;
}
