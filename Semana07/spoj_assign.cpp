/*
    COMPLEXITY(big O):
		time:n* n
		space: n

    DESCRIPTION:
		dynamic programming described below
*/

#include <iostream>
#include <string.h>

#define ll long long
#define u unsigned
#define nl std::endl

#define MAX 21

ll dp[(1 << MAX) + 5];
int arr[MAX + 5];
int n;


ll ddp(int pos, int total)
{
    // out of bounds check
    if (pos > n)
        return 0;
    // printf("do dp in %d %d\n", pos, total);
    // if every thing is already used then  return 1
    if (total == ((1 << n) - 1))
        return 1;
    //  if value has already been calculated
    if (dp[total] != -1)
        return dp[total];

    ll sum = 0;
    // iterate trough all the bits
    for (int i = 0; i < n; i++)
    {
        int flag = 1 << i;

        // the ith bit is already being used
        if ((total & flag) == flag)
            continue;

        // if the ith bit is turned on in the mask
        // then go to the next position and use the value
        if ((arr[pos] & flag) == flag)
            sum += ddp(pos + 1, total + flag);
    }
    return dp[total] = sum;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < n; i++)
        {
            int line = 0;
            for (int j = 0; j < n; j++)
            {
                int a;
                scanf("%d", &a);
                line += (a << j);
            }
            arr[i] = line;
        }
        printf("%llu\n", ddp(0, 0));
    }
}
