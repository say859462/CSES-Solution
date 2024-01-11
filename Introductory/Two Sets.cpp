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
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i;
    if (sum % 2)
    {
        cout << "NO"
             << "\n";
        return;
    }
 
    vector<int> ans;
    ll tmp = 0;
 
    sum /= 2;
    int cur = n;
    while (sum)
    {
        if (sum >= cur)
        {
            sum -= cur;
            ans.push_back(cur);
            cur--;
        }
        else
        {
            cur = sum;
        }
    }
 
    cout << "YES"
         << "\n";
    cout << ans.size() << "\n";
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
 
    cout << n - ans.size() << "\n";
 
    int ptr = 0;
    for (int i = n; i >= 1; i--)
    {
        if (ptr == ans.size() || ans[ptr] != i)
        {
            cout << i << " ";
        }
        else
            ptr++;
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
