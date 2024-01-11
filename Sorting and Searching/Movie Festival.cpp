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
    return a.second < b.second;
}
void solve()
{
    cin >> n;
 
    vector<pair<int, int>> movie;
 
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        movie.push_back(make_pair(x, y));
    }
 
    sort(movie.begin(), movie.end(), cmp);
    
 
    int end = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (end > movie[i].first)
            continue;
 
        end = movie[i].second;
        ans++;
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
