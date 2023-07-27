/*
    COMPLEXITY(big O):
        time:
        space:

    DESCRIPTION:

*/

#include <iostream>

#define ll long long
#define u unsigned
#define nl std::endl

#define MAX 2000
int L[MAX + 5][MAX + 5];
void printl(int n, int l)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < l; j++)
            printf("%d ", L[i][j]);
        printf("\n");
    }
}
int dist(char *a, char *b)
{

    int n, m, flag;

    for (n = 1; a[n - 1] != '\0'; n++)
        L[n][0] = n;
    for (m = 1; b[m - 1] != '\0'; m++)
        L[0][m] = m;

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
        {
            if (a[i - 1] != b[j - 1])
                flag = 1;
            else
                flag = 0;
            L[i][j] = std::min(L[i - 1][j - 1] + flag, std::min(L[i][j - 1] + 1, L[i - 1][j] + 1));
        }
    // printl(m, m);
    return L[n - 1][m - 1];
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        char a[MAX + 5], b[MAX + 5];
        scanf("%s %s", a, b);
        // printf("%s\n%s", a, b);
        printf("%d\n", dist(a, b));
    }
}
