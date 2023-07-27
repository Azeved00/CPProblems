/*
    COMPLEXITY(big O):
        time:O(V + E)
        space:

    DESCRIPTION:
        do Dijkstra algorithm in the matrix
        from up left[1][1]
        until down right [rows][cols]

*/

#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <array>

#define ll long long
#define u unsigned
#define nl std::endl
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x > y ? y : x)

#define MAXN 1005
#define INF 10000000
#define type std::array<int, 3>
// 0 -> dist, 1 -> row, 2 -> col

int mtrx[MAXN][MAXN];
int dist[MAXN][MAXN];
int visit[MAXN][MAXN];
std::priority_queue<type, std::vector<type>, std::greater<type>> Q;

void reset()
{
    memset(mtrx, -1, sizeof mtrx);
    memset(visit, 0, sizeof visit);
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            dist[i][j] = INF;
    while (!Q.empty())
        Q.pop();
}

void check(int posR, int posC, int ogPosR, int ogPosC)
{
    if (mtrx[posR][posC] != -1 && dist[posR][posC] > dist[ogPosR][ogPosC] + mtrx[posR][posC])
    {
        dist[posR][posC] = dist[ogPosR][ogPosC] + mtrx[posR][posC];
        Q.push({dist[posR][posC], posR, posC});
    }
}

void doDijkstra(int rows, int cols)
{
    dist[1][1] = mtrx[1][1];
    Q.push({mtrx[1][1], 1, 1});
    while (!Q.empty())
    {
        type a = Q.top();
        Q.pop();
        if (visit[a[1]][a[2]])
            continue;

        visit[a[1]][a[2]] = 1;
        if (visit[rows][cols])
            return;
        // up
        check(a[1] - 1, a[2], a[1], a[2]);
        // down
        check(a[1] + 1, a[2], a[1], a[2]);
        // left
        check(a[1], a[2] - 1, a[1], a[2]);
        // right
        check(a[1], a[2] + 1, a[1], a[2]);
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        reset();

        int rows, cols;
        scanf("%d", &rows);
        scanf("%d", &cols);

        for (int i = 1; i <= rows; i++)
            for (int j = 1; j <= cols; j++)
                scanf("%d", &mtrx[i][j]);

        doDijkstra(rows, cols);

        printf("%d\n", dist[rows][cols]);
    }
}
