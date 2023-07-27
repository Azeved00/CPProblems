/*
    COMPLEXITY(big O):
		time: size of matrix
        space: n*n (graph and visited)

    DESCRIPTION:
		Do a simple flood fill in the graph

*/

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <array>

#define ll long long
#define u unsigned
#define nl std::endl
#define a2 std::array<int, 2>
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x > y ? y : x)

#define MAXN 1000

char graph[MAXN][MAXN];
bool visited[MAXN][MAXN];
std::vector<a2> results(26);
void floodFill(char letter, int posX, int posY)
{
    if (graph[posX][posY] != letter || visited[posX][posY])
        return;

    visited[posX][posY] = true;
    floodFill(letter, posX + 1, posY);
    floodFill(letter, posX - 1, posY);
    floodFill(letter, posX, posY + 1);
    floodFill(letter, posX, posY - 1);
}

bool cmp(a2 i1, a2 i2)
{
    if (i1[1] == i2[1])
        return (i1[0] < i2[0]);
    return (i1[1] > i2[1]);
}
int main()
{
    int t;
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        for (int i = 0; i < 26; i++)
            results[i] = {i, 0};
        memset(graph, 0, sizeof graph);
        memset(visited, 0, sizeof visited);

        int rows, cols;
        scanf("%d %d", &rows, &cols);
        scanf("%*c");
        for (int i = 0; i <= rows + 1; i++)
        {
            for (int j = 0; j <= cols + 1; j++)
            {
                if (i == 0 || i > rows || j == 0 || j > cols)
                    graph[i][j] = '.';
                else
                    scanf("%c", &graph[i][j]);
            }
            if (!(i == 0 || i > rows))
                scanf("%*c");
        }

        for (int i = 1; i <= rows; i++)
            for (int j = 1; j <= cols; j++)
                if (!visited[i][j])
                {
                    results[graph[i][j] - 'a'][1]++;
                    floodFill(graph[i][j], i, j);
                }

        // print output
        printf("World #%d\n", tc);
        std::sort(results.begin(), results.end(), cmp);

        for (int i = 0; i < 26; i++)
            if (results[i][1])
                printf("%c: %d\n", results[i][0] + 'a', results[i][1]);
    }
}
