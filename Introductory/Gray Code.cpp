#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int MXN = 505;
vector<string> gray[17];
void build()
{
    gray[1].push_back("0");
    gray[1].push_back("1");
 
    for (int i = 2; i <= 16; i++)
    {
        vector<string> pre = gray[i - 1];
        vector<string> result;
        for (int j = 0; j < 1 << (i - 1); j++)
        {
            result.push_back("0");
        }
 
        for (int j = 0; j < 1 << (i - 1); j++)
        {
            result.push_back("1");
        }
        int idx = 0;
        for (int j = 0; j < gray[i - 1].size(); j++, idx++)
        {
            result[j] += gray[i - 1][j];
        }
 
        for (int j = pre.size() - 1, i = idx; j >= 0; j--, i++)
        {
            result[i] += pre[j];
        }
 
        for (int j = 0; j < result.size(); j++)
        {
            gray[i].push_back(result[j]);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
 
    build();
    for (int i = 0; i < (1 << n); i++)
    {
        cout << gray[n][i] << "\n";
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
