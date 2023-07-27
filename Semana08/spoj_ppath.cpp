/*
    COMPLEXITY(big O):
        time: ?
        space: n ( primes and the  )

    DESCRIPTION:
		Precaulculate the the graph
		do BFS to find shortest path
*/

#include <iostream>
#include <string.h>
#include <queue>
#include <array>

#define ll long long
#define u unsigned
#define nl std::endl
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x > y ? y : x)

#define MAXN 10005

bool prime[MAXN];
//O(1)
void sieve()
{
    memset(prime, 1, sizeof prime);
    for (int i = 2; i < 105; i++)
        if (prime[i])
            for (int j = i * i; j < MAXN; j += i)
                prime[j] = 0;
}

//O number of digits
void toArr(int arr[], int num)
{
    int d = 3;
    while (num > 0)
    {
        arr[d--] = num % 10;
        num /= 10;
    }
}
//O number of digits
int toNum(int arr[])
{
    int temp = 0, k = 0;
    while (k < 4)
    {
        temp = temp * 10 + arr[k];
        k++;
    }
    return temp;
}

int ans[MAXN];
//O V + E
int bfs(int strt, int end)
{
    memset(ans, -1, sizeof ans);
    std::queue<int> Q;
    Q.push(strt);
    ans[strt] = 0;

    while (!Q.empty())
    {
        int now = Q.front();
        if (now == end)
            return ans[now];

        Q.pop();
        int tempArr[4], tempNum;
        for (int p = 3; p >= 0; p--)
        {
            toArr(tempArr, now);
            for (int i = 0; i < 10; i++)
            {
                tempArr[p] = i;
                tempNum = toNum(tempArr);
                if (prime[tempNum] && ans[tempNum] == -1 && tempNum > 1000)
                {
                    Q.push(tempNum);
                    ans[tempNum] = ans[now] + 1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    sieve();
    while (t--)
    {
        int strt, end;
        scanf("%d %d", &strt, &end);

        int ans = bfs(strt, end);
        if (ans == -1)
            printf("Impossible\n");
        else
            printf("%d\n", ans);
    }
}
