#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define asort(x) sort(x.begin(), x.end())
using namespace std;
const int MXN = 200005;
int n, m, k, q, x, y;
void solve()
{
    cin >> n;
    vector<ll> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    ll ans = num[0];
    ll cur = num[0];
    for (int i = 1; i < n; i++)
 
    {
        // Kadane's Alg:長度+1的最大子陣列，要馬包含第i+1個元素或者不包含
        //  Maximun(i) indicate that the end of Maximun subarray of index i
        //  define : Maximum(i) =Max(Sum0_i,Sum1_i,...Sumi_i) where Sumx_i is the summation of subarray from index x to i
        //   Note :Maximum_x_(i+1) = Maximun_x_i + element[i+1]
        //  Maximun(i+1) = Max(Sum0_i + element[i+1] ,Sum1_i+element[i+1],...Sumi_i+element[i+1],element[i+1])
        //  Note: max(a+y,b+y,c+y) = max(a,b,c) + y
        //=> Maximun(i+1) = Max(Max(Sum0_i,Sum1_i,...,Sumi_i)+element[i+1],element[i]) => Max(Maximun(i)+element[i+1],element[i+1]) #
        cur = max(num[i], cur + num[i]);
        ans = max(cur, ans);
    }
    cout << ans << '\n';
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
