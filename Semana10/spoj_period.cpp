/*
    COMPLEXITY(big O):
        time: 3n
        space: 2n

    DESCRIPTION:
        get input O(n)
        calculate KMS array (pi) O(n)
        check output O(n)
*/

#include <iostream>
#include <string.h>

#define ll long long
#define u unsigned
#define nl std::endl
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x > y ? y : x)
#define set0(a) memset(a, 0, sizeof a)

#define MAXN 1000005
char str[MAXN];
int pi[MAXN];
int len;

void calcPi()
{
    pi[0] = 0;
    int k = 0;
    int i = 1;
    while (i < len)
    {
        if (str[i] == str[k])
            pi[i++] = ++k;
        else
        {
            if (k != 0)
                k = pi[k - 1];
            else
                pi[i++] = 0;
        }
    }
}
void out()
{
    for (int i = 0; i < len; i++)
    {
        if (!pi[i])
            continue;
        int ans = i + 1 - pi[i];
        if ((i + 1) % ans)
            continue;
        printf("%d %d\n", i + 1, (i + 1) / ans);
    }
}

int main()
{
    int t;
    scanf("%d%*c", &t);
    for (int tc = 1; tc <= t; tc++)
    {
        scanf("%d%*c", &len);
        for (int i = 0; i < len; i++)
            scanf("%c", &str[i]);
        scanf("%*c");
        printf("Test case #%d\n", tc);
        calcPi();
        out();
        printf("\n");
    }
}
