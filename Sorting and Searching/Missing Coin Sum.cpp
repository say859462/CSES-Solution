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
    vector<int> coin(n);
    for (int i = 0; i < n; i++)
        cin >> coin[i];
    ll sum = 0;
    // if a[i] - sum <= 1 => consider sum + 1 => we can use sum + 1 - a[i] + a[i] to get (sum + 1)
    // but if a[i] - sum > 1 means that a[i] is at least sum + 2 => what if we want to create sum + 1 ? there's no way ,since the summation further only can create maximum summation sum ,if we add a[i] , it definitely will greater than sum + 1 ,so sum + 1 is the answer
 
    asort(coin);
 
    for (int i = 0; i < n; i++)
    {
        if (coin[i] - sum > 1)
            break;
        sum += coin[i];
    }
 
    cout << sum + 1 << "\n";
 
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
