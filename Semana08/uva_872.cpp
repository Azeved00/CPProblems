/*
    COMPLEXITY(big O):
        time: test cases * (Vertecies + Edges)
        space: adj matrix + visited + nodes

    DESCRIPTION:
		Topological sorting using the rules given	
*/

#include <iostream>
#include <string.h>
#include <vector>
#include <map>

#define ll long long
#define u unsigned
#define nl std::endl
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x > y ? y : x)

#define MAXN 27
#define MAXV 55

bool nodes[MAXN];
std::vector<int> edges[MAXN];
int indegree[MAXN];
bool visited[MAXN];
bool answerd;

void doStuff(std::vector<int> res)
{
    bool flag = false;

    for (int i = 0; i < MAXN; i++)
    {

        if (indegree[i] || visited[i] || !nodes[i])
            continue;

        for (u ll j = 0; j < edges[i].size(); j++)
            indegree[edges[i][j]]--;

        visited[i] = true;
        res.push_back(i);
        doStuff(res);

        visited[i] = false;
        res.erase(res.end() - 1);
        for (u ll j = 0; j < edges[i].size(); j++)
            indegree[edges[i][j]]++;

        flag = true;
    }

    if (!flag && !res.empty())
    {
        answerd = true;
        for (u ll i = 0; i < res.size(); i++)
        {
            printf("%c", res[i] + 'A');
            if (i != res.size() - 1)
                printf(" ");
            else
                printf("\n");
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    scanf("%*c");

    while (t--)
    {
        answerd = false;
        memset(nodes, 0, sizeof nodes);
        for (int i = 0; i < MAXN; i++)
            edges[i].clear();
        memset(indegree, 0, sizeof indegree);
        memset(visited, 0, sizeof visited);

        char temp;
        scanf("%*c");

        while (1)
        {
            char v;
            scanf("%c%c", &v, &temp);
            nodes[v - 'A'] = true;
            if (temp == '\n')
                break;
        }

        while (1)
        {
            char out, in;
            scanf("%c<%c%c", &out, &in, &temp);
            edges[out - 'A'].push_back(in - 'A');
            indegree[in - 'A']++;

            if (temp == '\n')
                break;
        }

        std::vector<int> res;
        doStuff(res);

        if (!answerd)
            printf("NO\n");
        if (t)
            printf("\n");
    }
}
