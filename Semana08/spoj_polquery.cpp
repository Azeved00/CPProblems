/*
    COMPLEXITY(big O):
        time: N * Q
        space MAXN
    DESCRIPTION:
        simulate the path
*/

#include <iostream>
#include <string.h>
#include <vector>

#define ll long long
#define u unsigned
#define nl std::endl
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x > y ? y : x)

#define MAXN 100000
#define MAXE 500000

bool ans;
bool visited[MAXN];
std::vector<int> edges[MAXN];

void queryOne(int v, int end, int rOut, int rIn)
{
    if (v == end)
        ans = 1;
    if (ans)
        return;

    visited[v] = 1;
    int degree = edges[v].size();
    for (int i = 0; i < degree; i++)
        if (!visited[edges[v][i]] && !(rOut == v && rIn == edges[v][i]) && !(rIn == v && rOut == edges[v][i]))
            queryOne(edges[v][i], end, rOut, rIn);
}
void queryTwo(int v, int end)
{
    if (v == end)
        ans = 1;
    if (ans)
        return;

    visited[v] = 1;
    int degree = edges[v].size();
    for (int i = 0; i < degree; i++)
        if (!visited[edges[v][i]])
            queryTwo(edges[v][i], end);
}

int main()
{
    int n, e, q;
    scanf("%d %d", &n, &e);

    for (int i = 0; i < e; i++)
    {
        int out, in;
        scanf("%d %d", &out, &in);
        edges[out].push_back(in);
        edges[in].push_back(out);
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        ans = 0;
        memset(visited, 0, sizeof visited);

        int code, strt, end;
        int rs, re;
        scanf("%d %d %d", &code, &strt, &end);
        if (code == 1)
        {
            scanf("%d %d", &rs, &re);
            queryOne(strt, end, rs, re);
        }
        else
        {
            scanf("%d", &rs);
            visited[rs] = 1;
            queryTwo(strt, end);
        }

        if (ans)
            printf("da\n");
        else
            printf("ne\n");
    }
}