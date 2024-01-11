#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int MXN = 505;
int n, m;
int fac[10] = {0};
string str;
vector<string> result;
void build()
{
    for (int i = 1; i <= 9; i++)
        fac[i] = 1;
 
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 2; j <= i; j++)
            fac[i] *= j;
    }
}
void permutation(int cur)
{
    if (cur == str.size())
    {
        result.push_back(str);
        return;
    }
 
    for (int i = cur; i < str.size(); i++)
    {
        bool flag = 0;
        for (int j = cur; j < i; j++)
        {
            if (str[j] == str[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            continue;
        swap(str[cur], str[i]);
        permutation(cur + 1);
        swap(str[cur], str[i]);
    }
    return;
}
void solve()
{
 
    build();
    cin >> str;
    sort(str.begin(), str.end());
    int ans = 1;
    int cnt[26] = {0};
 
    for (int i = 0; i < str.size(); i++)
        cnt[str[i] - 'a']++;
 
    for (int i = 2; i <= str.size(); i++)
        ans *= i;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] <= 1)
            continue;
        ans /= fac[cnt[i]];
    }
 
    cout << ans << "\n";
    permutation(0);
    sort(result.begin(), result.end());
    for (string tmp : result)
    {
        cout << tmp << "\n";
    }
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
