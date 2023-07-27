/*
    COMPLEXITY(big O):
        time: size of input
        space: also size of input

    DESCRIPTION:
        calculate KMS array (pi)

*/

#include <iostream>
#include <string.h>

#define ll long long
#define u unsigned
#define nl std::endl
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x > y ? y : x)
#define set0(a) memset(a, 0, sizeof a)

#define MAXN 10000005
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
    if (!pi[len - 1])
    {
        printf("Just a legend\n");
        return;
    }

    // O(n)
    for (int i = pi[len - 1]; i < len - 1; i++)
        if (pi[i] == pi[len - 1])
        {
            for (int j = 0; j < pi[len - 1]; j++)
                printf("%c", str[j]);
            printf("\n");
            return;
        }

    if (!pi[pi[len - 1] - 1])
    {
        printf("Just a legend\n");
        return;
    }
    for (int i = 0; i < pi[pi[len - 1] - 1]; i++)
        printf("%c", str[i]);
    printf("\n");

    return;
}

int main()
{
    while (scanf("%c", &str[len]) && str[len] != '\n')
        len++;
    calcPi();
    out();
}
