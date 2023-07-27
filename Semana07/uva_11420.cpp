/*
    COMPLEXITY(big O):
        time:  n*n
        space: n * n * 2 (dp)

    DESCRIPTION:
		do dynamic programming
		described below
*/


#include <iostream>
#include <string.h>

#define ll long long
#define u unsigned
#define nl std::endl

#define MAX 66

long long int dp[MAX][MAX][2];

long long int ddp(int n, int s, int last)
{
    // printf("%d %d %d\n", n, s, last);
    //  goes down the wardrobe and checks all possible combinations that have
    //   s number of locked drawers and for that we need to know:
    //  number of drawers left, number of drawers left that need to be locked and
    //  to know wheter the last drawer was locked ot

    if (n < 0 || s < 0)
        return 0;
    // base cases
    if (n == 1) // 1 drawer left
    {
        if (s == 1) // 1 left to be secure
        {
            if (last == 1)
                return 1; // the last was is locked (can only be locked)
            else if (last == 0)
                return 0; // the last was not locked (impossible)
        }
        else if (s == 0) // ther are non left to be secure
        {
            if (last == 1)
                return 1; // the last one is locked (this one needs to be unlocked)
            else if (last == 0)
                return 2; //  the last on is unlocked (this one can be whatever)
        }
    }

    // if the number of drawers is lower than the number of drawers
    // that need to be secure than it is impossible
    if (n < s)
        return 0;

    // if the number of drawers left  is the same as
    // the number of drawers that need to be secure but the last one is not secure then
    // it is impossible
    if (n == s && !last)
        return 0;

    if (dp[n][s][last] != -1) // if the number has already been calculated
        return dp[n][s][last];

    if (last) // if the last drawer is locked then this one
        dp[n][s][last] = ddp(n - 1, s - 1, 1) + ddp(n - 1, s, 0);
    else // if the last drawer is unlocked
        dp[n][s][last] = ddp(n - 1, s, 1) + ddp(n - 1, s, 0);
    return dp[n][s][last];
}

int main()
{
    int n, s;
    memset(dp, -1, sizeof(dp)); //-1 means the value has not been calculated yet
    while (scanf("%d %d", &n, &s) && n >= 0 && s >= 0)
        printf("%lld\n", ddp(n, s, 1));
    return 0;
}
