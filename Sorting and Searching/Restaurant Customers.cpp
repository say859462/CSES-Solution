#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define asort(x) sort(x.begin(), x.end())
using namespace std;
const int MXN = 200005;
int n, m, k, q, x, y;
 
void solve()
{
    cin >> n;
 
    vector<pair<int, int>> customer;
 
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        customer.push_back(make_pair(x, 1));
        customer.push_back(make_pair(y, -1));
    }
 
    sort(customer.begin(), customer.end());
 
    int tmp = 0;
    int ans = 0;
 
    for (int i = 0; i < customer.size(); i++)
    {
        tmp += customer[i].second;
        ans = max(ans, tmp);
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
