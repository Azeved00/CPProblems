// TRIGALGE - Easy Calculation
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

#define ll long long
#define u unsigned
#define nl std::endl;

int main()
{
    int t;
    double a, b, c;
    std::cin >> t;

    while (t--)
    {
        std::cin >> a >> b >> c;
        double bot = 0.0, mid, top = 100000.0;
        for (int i = 0; i < 100; i++)
        {
            mid = (bot + top) / 2.0;

            if (c >= (a * mid) + (b * sin(mid)))
                bot = mid;
            else
                top = mid;
        }
        std::cout << std::fixed << std::setprecision(6) << bot << nl;
    }
}