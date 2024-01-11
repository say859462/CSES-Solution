#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define asort(x) sort(x.begin(), x.end())
using namespace std;
const int MXN = 200005;
int n, m, k, q, x, y;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
void solve()
{
    cin >> n >> x;
    vector<pair<int, int>> num;
 
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        num.push_back(make_pair(k, i + 1));
    }
    sort(num.begin(), num.end(), cmp);
 
    int i = 0, j = n - 1;
    while (i < j)
    {
        int sum = num[i].first + num[j].first;
        if (sum == x)
        {
            cout << num[i].second << " " << num[j].second << "\n";
            return;
        }
 
        if (sum < x)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    cout << "IMPOSSIBLE"
         << "\n";
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
