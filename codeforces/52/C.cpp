#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN 200020

ll tree[3 * MAXN];
ll lazy[3 * MAXN];
ll arr[MAXN];
int n, m;

void build(int v, int l, int r)
{
    if (l == r)
    {
        tree[v] = arr[r];
        return;
    }
    build(2 * v, l, (l + r) / 2);
    build(2 * v + 1, (l + r) / 2 + 1, r);
    tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}

ll update(int v, int l, int r, int l1, int r1, int k)
{
    if (r1 < l || l1 > r)
        return tree[v] + lazy[v];
    if (l >= l1 && r <= r1)
    {
        lazy[v] += k;
        return tree[v] + lazy[v];
    }
    int mid = (l + r) / 2;
    tree[v] = min(update(2 * v, l, mid, l1, r1, k), update(2 * v + 1, mid + 1, r, l1, r1, k));
    return tree[v] + lazy[v];
}

ll query(int v, int l, int r, int l1, int r1)
{
    if (r1 < l || l1 > r)
        return 1e15;
    if (l >= l1 && r <= r1)
        return tree[v] + lazy[v];
    int mid = (l + r) / 2;
    return min(query(2 * v, l, mid, l1, r1), query(2 * v + 1, mid + 1, r, l1, r1)) + lazy[v];
}

int main()
{
    char ch;
    ll cc;
    int x, y;

    scanf(" %d",&n);
    for (int i = 1; i <= n; i++)
        scanf(" %I64d",&arr[i]);

    build(1, 1, n);

    scanf(" %d",&m);
    for (int i = 0; i < m; i++)
    {
        scanf(" %d %d%c",&x,&y,&ch);
        x++;
        y++;
        if (ch == ' ')
        {
            scanf(" %I64d",&cc);
            if (x > y)
            {
                update(1, 1, n, x, n, cc);
                update(1, 1, n, 1, y, cc);
            }
            else update(1, 1, n, x, y, cc);
        }
        else
        {
            if (x > y)
                printf("%I64d\n",min(query(1, 1, n, x, n), query(1, 1, n, 1, y)));
            else printf("%I64d\n",query(1, 1, n, x, y));
        }
    }
    return 0;
}
