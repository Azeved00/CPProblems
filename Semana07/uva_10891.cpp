/*
    COMPLEXITY(big O):
        time: n*n
        space: n * n ( dp + visited + ps )

    DESCRIPTION:
		dynamic programming described below
*/

#include <iostream>
#include <string.h>

#define ll long long
#define u unsigned
#define nl std::endl
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x > y ? y : x)

#define NMAX 105

ll n;              // elements
ll dp[NMAX][NMAX]; // dp
bool visited[NMAX][NMAX];
ll ps[NMAX]; // prefix sum

ll ddp(int strt, int end)
{
    // if the value has been calculated
    if (visited[strt][end])
        return dp[strt][end];

    visited[strt][end] = 1;

    int m = 0;
    // from the left
    for (int i = strt + 1; i <= end; i++)
        m = MIN(m, ddp(i, end));
    // take from right
    for (int i = strt; i < end; i++)
        m = MIN(m, ddp(strt, i));

    return dp[strt][end] = ps[end] - ps[strt - 1] - m;
}

int main()
{
    // read input
    while (scanf("%lld", &n) && n != 0)
    {
        memset(visited, 0, sizeof visited);

        int a;
        ps[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a);
            ps[i] = ps[i - 1] + a;
        }
        // answer is your best score minus oponent best score
        printf("%lld\n", 2 * ddp(1, n) - ps[n]);
    }
}
