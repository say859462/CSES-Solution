#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int MXN = 505;
int n, m;
char grid[1005][1005];
int mov[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // LRUD
char op[4] = {'L', 'R', 'U', 'D'};
bool vis[1005][1005] = {0};
pair<int, int> pre[1005][1005];
pair<int, int> start, last;
struct node
{
    int x, y;
 
    node(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};
 
bool check(int dx, int dy)
{
    if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && !vis[dx][dy] && (grid[dx][dy] == '.' || grid[dx][dy] == 'B'))
        return true;
    return false;
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
            if (grid[i][j] == 'A')
                start = make_pair(i, j);
            if (grid[i][j] == 'B')
                last = make_pair(i, j);
        }
    }
 
    queue<node> q;
    q.push(node(start.first, start.second));
    string ans = "";
    bool flag = 0;
    while (!q.empty())
    {
 
        node tmp = q.front();
        q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int dx = tmp.x + mov[i][0];
            int dy = tmp.y + mov[i][1];
 
            if (check(dx, dy))
            {
                pre[dx][dy] = make_pair(tmp.x, tmp.y);
                vis[dx][dy] = true;
                if (grid[dx][dy] == 'B')
                {
                    ans.push_back(op[i]);
                    flag = 1;
                    break;
                }
                q.push(node(dx, dy));
            }
        }
        if (flag)
            break;
    }
 
    if (ans.empty())
    {
        cout << "NO";
    }
    else
    {
        cout << "YES"
             << "\n";
 
        pair<int, int> cur = pre[last.first][last.second];
 
        while (cur != start)
        {
            pair<int, int> tmp = pre[cur.first][cur.second];
            if (cur.first - tmp.first == 1)
            {
                ans.push_back('D');
            }
            else if (cur.first - tmp.first == -1)
            {
                ans.push_back('U');
            }
            else if (cur.second - tmp.second == 1)
            {
                ans.push_back('R');
            }
            else
            {
                ans.push_back('L');
            }
            cur = tmp;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        cout << ans << "\n";
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
