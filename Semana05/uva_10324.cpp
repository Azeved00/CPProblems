#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define u unsigned
#define nl std::endl
// answering with comulative sums
// since the input is static (no update query) we can simply have a vector to store the sum

int main()
{

    int n, a, b;
    char c;
    std::vector<int> sum;
    for (int i = 1; std::cin >> c && c != -1 && c != '\n'; i++)
    {
        sum.push_back(0);
        sum.push_back(c - '0');
        printf("Case %d:\n", i);
        while (scanf("%c", &c) && c != -1 && c != '\n')
        {
            if (c == '0')
                sum.push_back(sum.back());
            else if (c == '1')
                sum.push_back(sum.back() + 1);
            else
                break;
        }

        // for (int i : sum)
        //     std::cout << i << " ";

        std::cin >> n;
        while (n--)
        {
            std::cin >> a >> b;
            a++, b++;
            int s = sum[std::max(a, b)] - sum[std::min(a, b) - 1];
            if (s == 0 || s == abs(a - b) + 1)
                std::cout << "Yes" << nl;
            else
                std::cout << "No" << nl;
        }
        sum.clear();
    }
}