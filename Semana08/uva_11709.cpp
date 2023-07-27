/*
    COMPLEXITY(big O):
        time: N + E
        space: N

    DESCRIPTION:
        tarjan algorith

*/

#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <array>
#include <stack>

#define ll long long
#define u unsigned
#define nl std::endl
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x > y ? y : x)

#define MAXN 1001
#define MAXQ 1000001
#define MAXL 25
#define name std::array<char, MAXL>

std::vector<int> edges[MAXN];
std::map<name, int> nodes;

int low[MAXN], num[MAXN], idx, ans;
std::stack<int> S;
bool inS[MAXN];

void doStuff(int node)
{
    num[node] = idx;
    low[node] = idx++;
    S.push(node);
    inS[node] = 1;

    int len = edges[node].size();
    for (int i = 0; i < len; i++)
    {
        if (num[edges[node][i]] == -1)
        {
            doStuff(edges[node][i]);
            low[node] = min(low[node], low[edges[node][i]]);
        }
        else if (inS[edges[node][i]])
        {
            low[node] = min(low[node], num[edges[node][i]]);
        }
    }

    if (num[node] == low[node])
    {
        ans++;
        while (S.top() != node)
        {
            inS[S.top()] = false;
            S.pop();
        }
        inS[S.top()] = false;
        S.pop();
    }
}

name read()
{
    name temp;
    for (int i = 0; i < MAXL; i++)
        temp[i] = 0;

    char c;
    for (int i = 0; i < MAXL; i++)
    {
        scanf("%c", &c);
        if (c == '\n')
            break;
        temp[i] = c;
    }

    return temp;
}

void reset()
{
    memset(num, -1, sizeof num);
    memset(low, -1, sizeof low);
    memset(inS, 0, sizeof inS);
    while (!S.empty())
        S.pop();
    memset(edges, 0, sizeof edges);
    nodes.clear();
    idx = 0;
    ans = 0;
}
int main()
{
    int n, e;
    while (scanf("%d %d", &n, &e) && (n || e))
    {
        reset();
        scanf("%*c");

        for (int i = 0; i < n; i++)
            nodes[read()] = i;

        int out, in;
        for (int i = 0; i < e; i++)
        {
            out = nodes[read()];
            in = nodes[read()];

            edges[out].push_back(in);
        }

        for (int i = 0; i < n; i++)
            if (num[i] == -1)
                doStuff(i);

        printf("%d\n", ans);
    }
}