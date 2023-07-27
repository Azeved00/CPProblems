/*
    COMPLEXITY(big O):
        time: MAXI * N
        space: MAXI^2 + N (a litle bit to big)

    DESCRIPTION:
        doing euler path trough a graph
        nodes of the graph are a pair of 2 chars
        using a hash func to view the 2 chars as integers (so then we canuse the adj matrix) more easily

*/

#include <iostream>
#include <string.h>
#include <vector>
#include <array>

#define ll long long
#define u unsigned
#define s short
#define nl std::endl
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x > y ? y : x)

#define MAXN 200005
#define MAXI 7480

typedef std::array<char, 2> node;

int indegree[MAXI];
int outdegree[MAXI];
int n;
int edges[MAXI][MAXI];
char res[MAXN];

int hashFunc(node a)
{
    int f = a[0] - '0';
    int l = a[1] - '0';
    return f * 100 + l;
}

void eulerPath(int pos, int v)
{
    res[pos] = v / 100 + '0';
    for (int i = 0; i < MAXI; i++)
    {
        if (!edges[v][i])
            continue;
        edges[v][i]--;
        eulerPath(pos + 1, i);
    }

    if (pos == n)
    {
        for (int i = 0; i <= pos; i++)
        {
            printf("%c", res[i]);
            if (i == pos)
                printf("%c\n", v % 100 + '0');
        }
    }
}

int main()
{
    scanf("%d%*c", &n);

    int srt;
    for (int i = 0; i < n; i++)
    {
        int in, out;
        char temp[3];
        node a;

        scanf("%c%c%c%*c", &temp[0], &temp[1], &temp[2]);

        a[0] = temp[0];
        a[1] = temp[1];
        out = hashFunc(a);

        a[0] = temp[1];
        a[1] = temp[2];
        in = hashFunc(a);

        indegree[in]++;
        outdegree[out]++;
        srt = out;
        edges[out][in]++;
    }

    int count = 0;

    for (int i = 0; i < MAXI; i++)
        if ((indegree[i] + outdegree[i]) % 2 == 1)
        {
            if (outdegree[i] > indegree[i])
                srt = i;
            count++;
        }

    if (count > 2)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    eulerPath(0, srt);
}