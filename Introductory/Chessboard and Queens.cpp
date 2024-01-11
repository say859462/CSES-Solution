#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
using namespace std;
const int MXN = 505;
bool row[10] = {0};
bool ldia[20] = {0};
bool rdia[20] = {0};
char board[10][10];
int ans = 0;
void recursion(int cur)
{
    if (cur == 9)
    {
        ans++;
        return;
    }
 
    for (int i = 1; i <= 8; i++)
    {
        if (board[i][cur] == '.' && !row[i] && !ldia[i - cur + 8] && !rdia[cur + i])
        {
            row[i] = true;
            rdia[i + cur] = true;
            ldia[i - cur + 8] = true;
            recursion(cur + 1);
            row[i] = false;
            ldia[i - cur + 8] = false;
            rdia[cur + i] = false;
        }
    }
}
void solve()
{
 
    // Recursion
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            cin >> board[i][j];
 
    recursion(1);
 
    cout << ans << "\n";
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
