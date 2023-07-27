#include <iostream>
#include <string.h>
#include <algorithm>

#define ll long long
#define u unsigned
#define nl std::endl

#define MAXN 105
#define MAXM 10500

int clothes[MAXN][2];
int n, m;
int dp[MAXM];

int maxval(int strt, int end)
{
    int max = 0;
    for (int i = strt; i <= end; i++)
        max = std::max(max, dp[i]);
    return max;
}

int main()
{
    while (scanf("%d %d", &m, &n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%d %d", &clothes[i][0], &clothes[i][1]);
        // tried using geeksforgeeks algorithm for knapsac (couldnt do it)
        // trying different aproach where dp[j]!=0 only if it can be achived
        // and dp[j] will be the best possible way to achive j

        memset(dp, 0, sizeof(dp));
        if (m > 1800)
            m += 200;

        for (int i = 0; i < n; i++)
            for (int j = m; j - clothes[i][0] >= 0; j--)
                if (dp[j - clothes[i][0]] > 0 || j == clothes[i][0])
                    dp[j] = std::max(dp[j], dp[j - clothes[i][0]] + clothes[i][1]);

        // edge case: if we have a budget of (1800 < m <= 2000) we spend not only m>= 1900 but also 2000 < m <= 2100
        // bc if we spend more than 2000 we get refunded by 200
        // basically we are jumping the check of some values
        // if (2000 < m && m <= 2200)
        //    return std::max(maxval(0, m - 200 - 1), maxval(2001, m));
        // return maxval(0, m);
        int k = m - 200;
        int ans = 0;
        if (k > 1800 && k <= 2000)
        {
            for (int i = 0; i < k; i++)
                ans = std::max(ans, dp[i]);
            for (int i = 2001; i <= m; i++)
                ans = std::max(ans, dp[i]);
        }
        else
        {
            for (int i = 0; i <= m; i++)
                ans = std::max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}