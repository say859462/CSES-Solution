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
const int MXN = 2e5 + 5;
int n, m, x, y, k;
void solve()
{
    cin >> n;

    vi num(n);

    for (int i = 0; i < n; i++)
        cin >> num[i];

    multiset<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // find the greater element that num[i]
        if (s.upper_bound(num[i]) != s.end())
        {
            s.erase(s.upper_bound(num[i]));
            s.insert(num[i]);
        }
        else
        { // can not find an element which is greather than num[i]
            ans++;
            s.insert(num[i]);
        }
    }

    cout << ans << "\n";
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
