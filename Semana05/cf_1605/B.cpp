#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

#define ll long long
#define u unsigned
#define nl std::endl

int d(int l, int m, int r)
{
    return abs(l + r - (2 * m));
}
int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int val[3];
        std::cin >> val[0] >> val[1] >> val[2];
        std::sort(val, val + 3);
        // printf("%d %d %d %d \n", val[0], val[1], val[2], d(val[0], val[1], val[2]));
        int ans = d(val[0], val[1], val[2]) % 3;
        if (ans == 2)
            std::cout << 1 << nl;
        else
            std::cout << ans << nl;
    }
}