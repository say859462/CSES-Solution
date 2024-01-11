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
const int MXN = 1e5 + 5;
int n, m, x, y, k;
bool vis[MXN] = {0};
vector<int> edge[MXN];

void dfs(int u)
{
    vis[u] = true;
    for (int i : edge[u])
    {
        if (!vis[i])
            dfs(i);
    }
}
void solve()
{

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    vector<int> link;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ans++;
            link.push_back(i);
            dfs(i);
        }
    }

    cout << ans - 1 << "\n";
    for (int i = 0; i < link.size() - 1; i++)
    {
        cout << link[i] << " " << link[i + 1] << "\n";
    }

    return;
}
int main()
{

    // freopen("input.txt","r",stdin);    // 讀 file.in 檔
    // freopen("output.txt","w",stdout);  // 寫入 file.out 檔
    IO_FAST;

    solve();

    return 0;
}
