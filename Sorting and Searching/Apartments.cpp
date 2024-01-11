#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
using namespace std;
const int MXN = 200005;
int n, m, k;
int cnt[MXN] = {0};
void solve()
{
    cin >> n >> m >> k;
 
    vector<int> request(n);
    vector<int> sz(m);
 
    for (int i = 0; i < n; i++)
        cin >> request[i];
 
    for (int i = 0; i < m; i++)
        cin >> sz[i];
 
    sort(request.begin(), request.end());
    sort(sz.begin(), sz.end());
    int ans = 0;
 
    int i = 0, j = 0;
 
    while (i < n && j < m)
    {
        if (abs(request[i] - sz[j]) <= k)
        {
            i++, j++;
            ans++;
        }
        // house too large
        else if (sz[j] > request[i])
            i++;
        else
            j++;
    }
 
    cout << ans << "\n";
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
