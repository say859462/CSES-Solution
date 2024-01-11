#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int MXN = 505;
char grid[1005][1005] = {0};
bool vis[1005][1005] = {0};
int mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int ans = 0;
int n, m;
bool check(int dx, int dy)
{
    if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && !vis[dx][dy] && grid[dx][dy] == '.')
        return true;
    return false;
}
void dfs(int x, int y)
{
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int dx = x + mov[i][0];
        int dy = y + mov[i][1];
        if (check(dx, dy))
        {
            dfs(dx, dy);
        }
    }
}
void solve()
{
 
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                ans++;
                dfs(i, j);
            }
        }
    }
 
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
