#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(), x.end()
#define asort(x) sort(x.begin(), x.end())
#define fread                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
using namespace std;
 
const int MXN = 200005;
int n, m, k, q, x, y;
void solve()
{
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    bool vis[MXN] = {0};
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[num[i] - 1])
        {
            ans++;
        }
        vis[num[i]] = true;
    }
    cout << ans << "\n";
    return;
}
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    // fread;
 
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
