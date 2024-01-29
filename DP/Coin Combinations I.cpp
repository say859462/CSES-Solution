#include <bits/stdc++.h>
using namespace std;

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define IO_FAST \
    cin.tie(0); \
    ios::sync_with_stdio(0)

#define EPS 1e-3
#define cl(x) ((x << 1))
#define cr(x) ((x << 1) + 1)
#define lowbit(x) (x & -x)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define pi acos(-1)
#define all(a) (a).begin(), (a).end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (int)(x).size()
#define pq priority_queue // default priority higher first
#define ff first
#define ss second
#define ms(a, b, c) memset(a, b, c)
#define br cout << "\n"
#define EACH(x, a) for (auto &x : a)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
void print(ll t) { cout << t; }
void print(int t) { cout << t; }
void print(string t) { cout << t; }
void print(char t) { cout << t; }
void print(ld t) { cout << t; }
void print(double t) { cout << t; }
void print(ull t) { cout << t; }

template <class T, class V>
void print(pair<T, V> p)
{
    cout << "{";
    print(p.ff);
    cout << ",";
    print(p.ss);
    cout << "}";
    cout << '\n';
}
template <class T>
void print(vector<T> v, bool flag = true) // flag =true ascending order,otherwise descending
{
    if (flag)
        for (T i : v)
        {
            print(i);
            cout << " ";
        }
    else
        for (int i = sz(v) - 1; i >= 0; i--)
        {
            print(v[i]);
            cout << " ";
        }
    cout << '\n';
}
template <class T>
void print(set<T> v)
{
    for (T i : v)
    {
        print(i);
        cout << " ";
    }
    cout << '\n';
}
template <class T, class V>
void print(set<T, V> v)
{
    for (T i : v)
    {
        print(i);
        cout << " ";
    }
    cout << '\n';
}
template <class T>
void print(multiset<T> v)
{
    for (T i : v)
    {
        print(i);
        cout << " ";
    }
    cout << '\n';
}
template <class T, class V>
void print(map<T, V> v)
{
    for (auto i : v)
    {
        print(i);
        cout << " ";
    }
    cout << '\n';
}

// Operator overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second << '\n');
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
    插入t.insert();
    删除t.erase();
    求k在树中是第几大:t.order_of_key();
    求树中的第k大:t.find_by_order();
    前驱:t.lower_bound();
    后继t.upper_bound();
    a.join(b)b并入a 前提是两棵树的key的取值范围不相交
    a.split(v,b)key小于等于v的元素属于a，其余的属于b
    T.lower_bound   (x)   >=x的min的迭代器
    T.upper_bound((x)  >x的min的迭代器
    T.find_by_order(k) 有k个数比它小的数
*/

// comparator
// struct cmp
// {
//     bool operator()(pii const &a, pii const &b) const
//     {
//         return a.first == b.first ? a.second < b.second : a.first > b.first;
//     }
// };
const int mod = 1e9 + 7;
const int MXN = 1e6 + 5;
int n, m, x, y, k;

void solve()
{
    cin >> n >> x;
    vl coin(n);
    cin >> coin;

    ll dp[MXN] = {0};
    // dp[i] = the number of combination can produce i dollar
    dp[0] = 1;

    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + coin[j] <= 1e6)
            {
                dp[i + coin[j]] = (dp[i + coin[j]] % mod + dp[i] % mod) % mod;
            }
        }
    }
    print(dp[x] % mod);

    return;
}
int main()
{

    // freopen("input.txt","r",stdin);    // 讀 file.in 檔
    // freopen("output.txt","w",stdout);  // 寫入 file.out 檔
    IO_FAST;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}
