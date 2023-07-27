#include <iostream>
#include <algorithm>

#define ll long long
#define u unsigned
#define nl std::endl
#define TMAX 1000
#define RMAX 1000000

ll int tree[TMAX + 5];
std::pair<int, int> roads[RMAX + 5];
int n, m;

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
    while (idx <= m)
    {
        // printf("updating %d from %d to %d\n", idx, tree[idx], tree[idx] + v);
        tree[idx] += v;
        idx += (idx & -idx);
    }
}

int main()
{
    int t, k;
    ll int ans;
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        ans = 0;
        for (int i = 0; i < TMAX; i++)
            tree[i] = 0;

        for (int i = 0; i < RMAX; i++)
            roads[i] = {0, 0};

        scanf("%d %d %d", &n, &m, &k);

        for (int i = 0; i < k; i++)
            scanf("%d %d", &roads[i].first, &roads[i].second);
        std::sort(roads, roads + k);

        // for (int i = 0; i < k; i++)
        //     printf("%d %d\n", roads[i].first, roads[i].second);

        // for 2 roads (1 and 2) t cross
        //  a1 < a2 && b1 > b2
        //  a1 > a2 && b1 < b2
        // meaning if a1== a2 or b1==b2 there are no crosses
        // and both grater (or lower) there are also no crosses
        // so we sort the roads and backwards(start with highest a) so that we only have
        // to count every road with lower b wich is comulative sum

        for (int i = k - 1; i >= 0; i--)
        {

            // printf("%d -> %d\n", roads[i].first, roads[i].second);

            // printf("update %d, ans %d\n", roads[i].second, ans);
            update(roads[i].second, 1);

            // for (int j = 1; j <= m; j++)
            //     printf("%d = %d\n", j, tree[j]);

            ans += read(roads[i].second - 1);
        }
        printf("Test case %d: %lld\n", tc, ans);
    }
}