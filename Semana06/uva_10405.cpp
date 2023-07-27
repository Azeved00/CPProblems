#include <iostream>
#include <string>
#include <algorithm>

#define ll long long
#define u unsigned
#define nl std::endl

#define MAX 100000

int LCS(std::string a, std::string b)
{
    int as = a.size(), bs = b.size();
    int L[as + 1][bs + 1];

    for (int i = 0; i <= as; i++)
        for (int j = 0; j <= bs; j++)
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = std::max(L[i - 1][j], L[i][j - 1]);

    return L[as][bs];
}
int main()
{
    std::string a, b;
    while (std::getline(std::cin, a) && a[0] != EOF)
    {
        std::getline(std::cin, b);
        printf("%d\n", LCS(a, b));
    }
}