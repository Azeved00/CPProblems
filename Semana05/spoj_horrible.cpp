#include <iostream>

#define ll long long
#define u unsigned
#define nl std::endl

#define MAX 100005

ll int BIT1[MAX], BIT2[MAX];
int n;

ll int read(int idx, int tree)
{
    ll int sum = 0;
    while (idx > 0)
    {
        // printf("reading %d - %d, total %d\n", idx, tree[idx], sum);
        if (tree == 1)
            sum += BIT1[idx];
        else
            sum += BIT2[idx];

        idx -= (idx & -idx);
    }
    return sum;
}
void update(int idx, ll int v, int tree)
{
    while (idx <= n)
    {
        // printf("updating %d from %d to %d\n", idx, tree[idx], tree[idx] + v);
        if (tree == 1)
            BIT1[idx] += v;
        else
            BIT2[idx] += v;

        idx += (idx & -idx);
    }
}
ll int query(int idx)
{
    return (read(idx, 1) * idx) - read(idx, 2);
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int c;
        int op, p, q;
        ll int v;
        for (int i = 0; i < MAX; i++)
        {
            BIT1[i] = 0;
            BIT2[i] = 0;
        }
        scanf("%d %d", &n, &c);
        while (c--)
        {
            scanf("%d %d %d", &op, &p, &q);
            if (op == 0)
            {
                // update [p,q] by v
                scanf("%lld", &v);

                // tree 1
                update(p, v, 1);
                update(q + 1, -v, 1);
                // tree 2
                update(p, v * (p - 1), 2);
                update(q + 1, (-v * q), 2);
            }
            else
            {
                // read [p,q]
                printf("%lld\n", query(q) - query(p - 1));
            }
        }
    }
}