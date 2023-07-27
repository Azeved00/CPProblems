#include <iostream>
#include <vector>

#define ll long long
#define u unsigned
#define nl std::endl

int main()
{
    int n, p, a;
    std::cin >> n;
    for (int cases = 1; cases <= n; cases++)
    {
        int max = 0, strt = 0, end = 0; // save best sub array
        int now = 0, last = 1;          // for the array being evaluated

        std::cin >> p;
        for (int j = 2; j <= p; j++) // iterate trough array (O(n))
        {
            std::cin >> a;
            now += a;

            // printf("a = %d ,now = %d,last = %d\n", a, now, last);

            if (now >= max)
            {
                if (now > max || (now == max && (end - strt) < (j - last))) // because we want the one with highest numer of stops
                    strt = last, end = j;
                max = now;
            }
            if (now < 0)
                now = 0, last = j;
        }
        // output
        if (max > 0)
            printf("The nicest part of route %d is between stops %d and %d\n", cases, strt, end);
        else
            printf("Route %d has no nice parts\n", cases);
    }
}