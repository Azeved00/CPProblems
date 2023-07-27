/*
    COMPLEXITY(big O):
        time: n log m
        space: m²

    DESCRIPTION:
        prim's algorithm for MSTs

*/

#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <array>

#define ll long long
#define u unsigned
#define nl std::endl
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x > y ? y : x)

#define MAXN 1005
#define pair std::array<int, 2>

std::vector<pair> adj[MAXN];
bool inMST[MAXN];

void reset()
{
    memset(inMST, 0, sizeof inMST);
    adj->clear();
}

int prim()
{
    std::priority_queue<pair, std::vector<pair>, std::greater<pair>> PQ;

    int strt = 1, total = 0;
    PQ.push({0, strt});

    while (!PQ.empty())
    {
        pair temp = PQ.top();
        PQ.pop();

        if (inMST[temp[1]])
            continue;

        inMST[temp[1]] = 1;
        total += temp[0];

        int len = adj[temp[1]].size();

        for (int i = 0; i < len; i++)
            PQ.push(adj[temp[1]][i]);
    }

    return total;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        reset();
        int p, n, m;
        scanf("%d %d %d", &p, &n, &m);
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            adj[a].push_back({c, b});
            adj[b].push_back({c, a});
        }
        printf("%d\n", prim() * p);
    }
}