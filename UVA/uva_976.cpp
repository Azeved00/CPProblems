#include <iostream>
#include <string.h>
#include <queue>
#include <array>

#define ll long long
#define u unsigned
#define nl std::endl
#define pi std::array<int, 2>
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x > y ? y : x)

#define MAXC 1000
#define MAXB 105

ll int spaces, r, c;
ll int dp[MAXB][MAXC];
// do dp is bc there are only to states that a certain colun can be in
// either it belongs to the answer or it doesnt
// we want the minimun of everithing so we just do the minimun between everithing
ll int ddp(ll int pos, ll int remaining)
{
    // this is for bounds
    if (pos > c)
        return 0;
    if (pos > (c - remaining - (spaces * (remaining - 1))))
        return 1000;

    // printf("for %d %d\n", pos, remaining);
    //  aka we are missing one bridge
    if (!remaining)
        return 0;

    // if the value has been calculated then there is no need to calculate it again
    if (dp[remaining][pos])
        return dp[remaining][pos];

    //  using means get the value at current position
    //  skipping some position(minimun spaces) and trying again
    ll int use = dp[0][pos] + ddp(pos + spaces + 1, remaining - 1);
    // printf("\tfor %d %d : use is %d\n", pos, remaining, use);
    //   not using means trying the next position
    ll int nuse = ddp(pos + 1, remaining);
    // printf("\tfor %d %d : nuse is %d\n", pos, remaining, nuse);

    dp[remaining][pos] = MIN(use, nuse);
    // printf("dp[%d][%d] = %d\n", remaining, pos, dp[remaining][pos]);
    return dp[remaining][pos];
}

void read_input()
{

    // read the matrix
    // Read using recursive function to determine wich shore it is on
    // assign 0 to sea, 1 to one shore (up) and 2 the other shore(down)

    char a;
    int graph[MAXC][MAXC];
    std::queue<pi> q;

    memset(graph, 0, sizeof graph);

    for (int i = 0; i < r; i++)
    {
        scanf("%c", &a);
        for (int j = 0; j < c; j++)
        {
            scanf("%c", &a);
            // printf("%d %d = %c\n", i, j, c);
            if (a == '#')
            {
                if (i == 0)
                    graph[i][j] = 1;
                else if (i == r - 1)
                    graph[i][j] = 2;
                else
                    q.push({i, j});
            }
            else
                graph[i][j] = 0;
        }
    }
    while (!q.empty())
    {
        pi a = q.front();
        q.pop();

        if (graph[a[0] + 1][a[1]] != 0)
            graph[a[0]][a[1]] = graph[a[0] + 1][a[1]];
        else if (graph[a[0]][a[1] + 1] != 0)
            graph[a[0]][a[1]] = graph[a[0]][a[1] + 1];
        else if (graph[a[0] - 1][a[1]] != 0)
            graph[a[0]][a[1]] = graph[a[0] - 1][a[1]];
        else if (graph[a[0]][a[1] - 1] != 0)
            graph[a[0]][a[1]] = graph[a[0]][a[1] - 1];
        else
            q.push(a);
    }

    /*for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }*/

    // trasform graph into int array
    // calculate the distance between shore 1 and shore 2
    for (int i = 0; i < c; i++)
    {
        int count = 0;
        for (int j = 0; j < r; j++)
        {
            if (graph[j][i] == 1)
                count = 0;
            else if (graph[j][i] == 2)
                break;
            else
                count++;
        }
        dp[0][i] = count;
    }

    // for (int i = 0; i < c; i++)
    //     printf("%d ", dp[0][i]);
    // printf("\n");
    //   number array will be stored in the first line of dp
}

int main()
{

    int n; // rows, number
    // couns and spaces are global bc we use them in ddp
    while (scanf("%lld %lld %d %lld", &r, &c, &n, &spaces) == 4)
    {
        memset(dp, 0, sizeof(dp));
        read_input();
        printf("%lld\n", ddp(0, n));
        /*for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < c; j++)
                printf("%4d", dp[i][j]);
            printf("\n");
        }*/
    }
}