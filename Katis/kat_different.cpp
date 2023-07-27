/*
    COMPLEXITY(big O):
        time: O(n)
		space: O(1)

    DESCRIPTION:
		Very Simple Math
*/     

#include <iostream>

int main()
{

    long long int a, b;
    while (scanf("%lld %lld", &a, &b) != -1)
    {
        if (a < b)
            printf("%lld\n", b - a);
        else
            printf("%lld\n", a - b);
    }
}
