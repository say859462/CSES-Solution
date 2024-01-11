#include <bits/stdc++.h>

using namespace std;
#define IO_FAST \
    cin.tie(0); \
    ios::sync_with_stdio(0)
#define ll long long
#define LL long long
#define ld long double
#define EPS 1e-3
#define cl(x) ((x << 1))
#define cr(x) ((x << 1) + 1)
#define FZ(x) memset(x, -1, sizeof(x))
#define lowbit(x) (x & -x)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define MP make_pair
#define PB push_back
#define pi acos(-1)
#define ALL(a) a.begin(), a.end()
#define SZ(x) ((int)x.size())
#define asort(a) sort(a.begin(), a.end())                 // 升冪排序
#define dsort(a) sort(a.begin(), a.end(), greater<int>()) // 降冪排序
#define dsortll(a) sort(a.begin(), a.end(), greater<ll>())
const int mod = 1e9 + 9;
const int mx = 1e4 + 5;

void solve()
{
    int n, m;
    cin >> n >> m;
    int l = 1;
    int ind[n + 2] = {0}, a[n + 1] = {0};
    ind[n + 1] = n + 1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ind[x] = i;
        a[i] = x;
    }
    int c = 1;
    for (int i = 1; i <= n; i++)
    {
        if (l > ind[i])
            c++;
        l = ind[i];
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        int r = a[x], s = a[y];
        swap(a[x], a[y]);
        if (ind[r - 1] <= ind[r] && ind[r - 1] > y)
            c++;
        if (ind[r - 1] > ind[r] && ind[r - 1] <= y)
            c--;
        if (ind[r] <= ind[r + 1] && y > ind[r + 1])
            c++;
        if (ind[r] > ind[r + 1] && y <= ind[r + 1])
            c--;
        ind[r] = y;
        if (ind[s - 1] <= ind[s] && ind[s - 1] > x)
            c++;
        if (ind[s - 1] > ind[s] && ind[s - 1] <= x)
            c--;
        if (ind[s] <= ind[s + 1] && x > ind[s + 1])
            c++;
        if (ind[s] > ind[s + 1] && x <= ind[s + 1])
            c--;
        ind[s] = x;
        cout << c << endl;
    }
}
int main()
{

    // freopen("input.txt","r",stdin);    // 讀 file.in 檔
    // freopen("output.txt","w",stdout);  // 寫入 file.out 檔
    IO_FAST;

    solve();
    return 0;
}
