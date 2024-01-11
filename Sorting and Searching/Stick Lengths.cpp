#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(), x.end()
#define asort(x) sort(x.begin(), x.end())
 
using namespace std;
 
const int MXN = 200005;
int n, m, k, q, x, y;
void solve()
{
 
    cin >> n;
    vector<ll> stick(n);
    for (int i = 0; i < n; i++)
        cin >> stick[i];
    asort(stick);
 
    ll ans = 0;
    ll mid = stick[n / 2];
 
    for (int i = 0; i < n; i++)
    {
        ans += abs(mid - stick[i]);
    }
    cout << ans << "\n";
    return;
}
void fread()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    return;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    // fread();
 
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
