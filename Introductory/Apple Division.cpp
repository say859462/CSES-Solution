#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
using namespace std;
const int MXN = 505;
void solve()
{
    int n;
    cin >> n;
    vector<int> w(n);
 
    for (int i = 0; i < n; i++)
        cin >> w[i];
 
    ll ans = INFLL;
 
    for (int i = 1; i < (1 << n); i++)
    {
        ll left = 0;
        ll right = 0;
        int tmp = i;
        int cnt = 0;
        int idx = 0;
        while (tmp || cnt < n)
        {
            if (tmp & 1)
                left += w[idx];
            else
                right += w[idx];
            idx++;
            cnt++;
            tmp >>= 1;
        }
        ans = min(ans, abs(left - right));
    }
 
    cout << ans << '\n';
 
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
