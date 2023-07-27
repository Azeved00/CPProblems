#include <iostream>
#include <cmath>

#define ll long long
#define u unsigned
#define nl std::endl;

ll int n, heights[10001], costs[10001];

ll cost(double h)
{
    ll sum = 0;
    for (int i = 0; i < n; i++)
        sum += std::fabs((h - heights[i]) * costs[i]);
    // printf("debug - sum of %lf = %lf\n", h, sum);
    return sum;
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int maxh = -1;
        std::cin >> n;
        for (int i = 0; i < n; i++)
        {
            std::cin >> heights[i];
            if (heights[i] > maxh)
                maxh = heights[i];
        }
        for (int i = 0; i < n; i++)
            std::cin >> costs[i];

        double l = 0, r = maxh + 1, ml, mr;
        while (r - l > 1)
        {
            ml = l + (r - l) / 3.0;
            mr = r - (r - l) / 3.0;
            // printf("debug - l = %lf, ml = %lf, mr = %lf ,r = %lf\n", l, ml, mr, r);
            if (cost(ml) > cost(mr))
                l = ml;
            else
                r = mr;
        }
        std::cout << std::min(cost(std::floor(l)), cost(std::ceil(l))) << nl;
    }
}
