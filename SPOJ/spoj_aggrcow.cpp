#include <iostream>
#include <algorithm>

#define ll long long
#define u unsigned
#define nl std::endl;

int n, c, stalls[100001];
bool possible(int val, int stalls[])
{
    // printf("debug - checking %d\n", val);
    int cnt = 1, last = stalls[0];
    for (int i = 1; i < n; i++)
    {
        // printf("chekcing stall at %d, last cow at %d -> %d\n", i, last, stalls[i] - last);
        if (stalls[i] - last >= val)
        {
            last = stalls[i];
            cnt++;
            if (cnt == c)
                return true;
        }

        // printf("debug - count is %d\n", cnt);
    }
    // std::cout << nl;
    return false;
}
int main()
{
    int t;

    std::cin >> t;

    while (t--)
    {
        std::cin >> n >> c;
        for (int i = 0; i < n; i++)
            std::cin >> stalls[i];

        std::sort(stalls, stalls + n);

        int l = 0, r = stalls[n - 1], mid, max = -1;
        while (l < r)
        {
            mid = (l + r) / 2;

            // printf("debug - l = %d, mid = %d, r = %d\n", l, mid, r);

            if (possible(mid, stalls))
            {
                if (mid > max)
                    max = mid;
                l = mid + 1;
            }
            else
                r = mid;
        }
        std::cout << max << nl;
    }
}

/*
9
500000000
6
4*/
