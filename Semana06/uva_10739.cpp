#include <iostream>
#include <string.h>
#include <vector>

#define ll long long
#define u unsigned
#define nl std::endl

#define MAXL 1005

int length;
char words[2][MAXL];
int dp[MAXL][MAXL];

// we want a palindrome aka reads the same from back to the from
// for that we will divide the string in 2 parts
// if the string has length % 2 ==  1 tehn we can ignore the middle letter as it dosent matter
// then we will just do edit distance of one half to the other (but reversed)

// this approach does not work bc sometimes taking one letter  from the word is better
// so as a frind suggested i will go with edist the hole string and itself reserved and then divide by 2
void printl()
{
    for (int i = 0; i <= length; i++)
    {
        for (int j = 0; j <= length; j++)
            printf("%2d ", dp[i][j]);
        printf("\n");
    }
}
int dist()
{

    // printf("dist between : %s and %s\n", words[0] + 1, words[1]);

    for (int n = 0; n <= length; n++)
        dp[n][0] = n;
    for (int m = 0; m <= length; m++)
        dp[0][m] = m;

    for (int i = 1; i <= length; i++)
        for (int j = 1; j <= length; j++)
        {
            if (words[0][i] == words[1][j])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + std::min(dp[i - 1][j - 1], std::min(dp[i][j - 1], dp[i - 1][j]));
        }
    // printl();

    return dp[length][length];
}
void rev(std::vector<char> str)
{
    int i = 1, j = length;
    while (!str.empty())
    {
        words[0][i++] = str.back();
        words[1][j--] = str.back();
        // std::cout << words[0][i] << nl;
        str.pop_back();
    }
}

int main()
{
    int t;
    scanf("%d\n", &t);
    for (int tt = 1; tt <= t; tt++)
    {
        memset(dp, 0, sizeof dp);
        std::vector<char> str;
        char c;
        for (length = 0; scanf("%c", &c) && c != '\n'; length++)
            str.push_back(c);
        rev(str);
        printf("Case %d: %d\n", tt, dist() / 2);
    }
}