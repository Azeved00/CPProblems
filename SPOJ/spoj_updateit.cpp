#include <iostream>
#include <stdio.h>

#define ll long long
#define nl std::endl

#define MAX 10005

ll int tree[MAX];
int n;

ll int read(int idx)
{
    ll int sum = 0;
    while (idx > 0)
    {
        // printf("reading %d - %d, total %d\n", idx, tree[idx], sum);
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
void update(int idx, int v)
{
    while (idx <= MAX)
    {
        // printf("updating %d from %d to %d\n", idx, tree[idx], tree[idx] + v);
        tree[idx] += v;
        idx += (idx & -idx);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        for (int i = 0; i < MAX; i++)
        {
            tree[i] = 0;
        }
        // printf("test cases = %d\n", t);
        int u, q;
        scanf("%d %d", &n, &u);
        n++;
        // printf("array length %d\nupdate querys %d\n", n, u);

        while (u--)
        {
            int a, b, v;
            scanf("%d %d %d", &a, &b, &v);
            // printf("update from %d to %d add %d\n", a, b, v);

            update(a + 1, v);
            update(b + 2, -v);
            // for (int j = 1; j <= n; j++)
            //     printf("%d = %d\n", j, tree[j]);
            // std::cout << nl;
        }

        scanf("%d", &q);
        while (q--)
        {
            int a;
            scanf("%d", &a);
            // printf("query %d\n", a);
            printf("%lld\n", read(a + 1));
        }
    }
}
