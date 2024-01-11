#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define asort(x) sort(x.begin(), x.end())
using namespace std;
const int MXN = 200005;
int n, m, k, q;
 
void solve()
{
    cin >> n >> m;
    multiset<int> s;
    vector<int> pay(m);
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        s.insert(tmp);
    }
 
    for (int i = 0; i < m; i++)
        cin >> pay[i];
 
    for (int i = 0; i < m; i++)
    {
        auto it = s.upper_bound(pay[i]);
        if (it == s.begin())
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << *(--it) << "\n";
            s.erase(it);
        }
    }
 
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
