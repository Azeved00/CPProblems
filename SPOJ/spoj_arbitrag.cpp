/*
    COMPLEXITY(big O):
        time: N^3
        space: N^2

    DESCRIPTION:
        Floyd Warshal Algorithm

*/

#include <iostream>
#include <string.h>
#include <map>
#include <string>

#define ll long long
#define u unsigned
#define nl std::endl
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x > y ? y : x)
#define set0(a) memset(a, 0, sizeof a)

#define MAXN 50
std::map<std::string, int> M;
double graph[MAXN][MAXN];

bool floydWarshall(int n)
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                graph[i][j] = max(graph[i][j], graph[i][k] * graph[k][j]);

    for (int i = 0; i < n; i++)
        if (graph[i][i] > 1.0)
            return 1;
    return 0;
}

int main()
{
    for (int tc = 1;; tc++)
    {
        memset(graph, 0.0, sizeof graph);
        M.clear();
        int n, e;
        scanf("%d", &n);
        if (n == 0)
            return 0;
        for (int i = 0; i < n; i++)
        {
            std::string s;
            std::cin >> s;
            M[s] = i;
        }
        std::cin >> e;
        for (int i = 0; i < e; i++)
        {
            std::string source, dest;
            double val;
            std::cin >> source >> val >> dest;
            graph[M[source]][M[dest]] = val;
        }

        printf("Case %d: ", tc);
        if (floydWarshall(n))
            printf("Yes\n");
        else
            printf("No\n");
    }
}