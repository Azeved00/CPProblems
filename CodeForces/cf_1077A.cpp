/*
    COMPLEXITY(big O):
        time: O(1) * test casses
		space: O(1)

    DESCRIPTION:
		Very Simple Math
*/

#include <iostream>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long int pos;
        long long int a, b, k;
        scanf("%lld %lld %lld", &a, &b, &k);
        if (k % 2 == 0)
            pos = (a - b) * (k / 2);
        else
            pos = (((a - b) * (k - 1)) / 2) + a;

        printf("%lld\n", pos);
    }
}
