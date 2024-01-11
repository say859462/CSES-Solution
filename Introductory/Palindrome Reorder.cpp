#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int MXN = 505;
int cnt[26] = {0};
void solve()
{
    string str;
    cin >> str;
    int odd = 0;
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        cnt[str[i] - 'A']++;
    }
 
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % 2)
            odd++;
    }
 
    if ((len % 2 == 0 && odd) || (len % 2 && odd > 1))
    {
        cout << "NO SOLUTION"
             << "\n";
        return;
    }
    string tmp;
    string ans;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % 2)
        {
            for (int j = 0; j < cnt[i]; j++)
                tmp.push_back('A' + i);
            continue;
        }
        for (int j = 0; j < cnt[i] / 2; j++)
            ans.push_back('A' + i);
    }
    cout << ans;
    if (!tmp.empty())
    {
        cout << tmp;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
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
