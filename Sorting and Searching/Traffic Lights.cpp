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
    cin >> x >> n;
    vi num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];

    // store further traffic lights
    set<int> s;
    // store every length of passage
    multiset<int> s2;

    s.insert(0);
    s.insert(x);
    s2.insert(x);
    for (int i = 0; i < n; i++)
    {

        auto it = s.upper_bound(num[i]);
        int high = *(it);
        int low = *(--it);
        s2.erase(s2.find(high - low));

        s2.insert(num[i] - low);
        s2.insert(high - num[i]);
        s.insert(num[i]);

        cout << *(s2.rbegin()) << " ";
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
