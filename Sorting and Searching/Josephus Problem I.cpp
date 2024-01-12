/*
    Double circular linked list
*/

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
const int MXN = 1e5 + 5;
int n, m, x, y, k;
struct node
{
    int data;
    node *next;
    node *pre;
    node() {}

    node(int _data)
    {
        data = _data;
        next = nullptr;
        pre = nullptr;
    }
};

struct circular_linked_list
{
    int size = 0;
    node *head = nullptr;
    node *tail = nullptr;
    circular_linked_list()
    {
    }
    void push_back(int data)
    {
        if (size == 0)
        {
            head = new node(data);
            head->next = head;
            head->pre = head;
            tail = head;
        }
        else
        {
            tail->next = new node(data);
            // record the previous node
            node *tmp = tail;
            tail = tail->next;
            tail->pre = tmp;

            // make it circular
            tail->next = head;
        }
        size++;
    }
    // return the node from the next of deleted node
    node *del(node *pos)
    {
        node *result;
        if (pos == head)
        {
            tail->next = head->next;
            // head->next become new head
            head = head->next;
            delete pos;

            result = head;
        }
        else if (pos == tail)
        {
            pos->pre->next = head;
            tail = pos->pre;

            delete pos;
            result = head;
        }
        else
        {
            result = pos->next;
            pos->pre->next = pos->next;
            pos->next->pre = pos->pre;
            delete pos;
        }

        size--;
        return result;
    }
};

void solve()
{

    cin >> n;

    circular_linked_list *lst = new circular_linked_list();

    for (int i = 1; i <= n; i++)
    {
        lst->push_back(i);
    }

    node *cur = lst->head;
    node *tmp;
    while (lst->size > 0)
    {
        cur = cur->next;
        cout << cur->data << " ";
        tmp = lst->del(cur);
        cur = tmp;
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



/*
    red_black tree method
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> t;
void solve()
{

    cin >> n;
    k = 1;
    for (int i = 1; i <= n; i++)
        t.insert(i);

    int idx = k % n;

    while (n--)
    {
        auto u = t.find_by_order(idx);
        cout << *u << " ";
        t.erase(u);
        if (n)
            idx = (idx % n + k) % n;
    }

    return;
}

*/
