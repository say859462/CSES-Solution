#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
using namespace std;
const int MXN = 200005;
int n, m, k;
void solve()
{
    cin >> n >> k;
    vector<int> w(n);
    bool vis[MXN] = {0};
    int ans = 0;
 
    for (int i = 0; i < n; i++)
        cin >> w[i];
 
    sort(w.begin(), w.end());
 
    // let boats have the child as many as possible
    int i = n - 1, j = 0;
    int remain = 0;
    while (i >= j)
    {
        ans++;
        
        remain = k - w[i];
 
        if (w[j] <= remain)
            j++;
 
        i--;
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
