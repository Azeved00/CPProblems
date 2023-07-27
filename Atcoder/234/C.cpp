#include <iostream>
#include <string.h>

#define ll long long
#define u unsigned
#define nl std::endl
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x > y ? y : x)

void ans(ll u n)
{
    int bin[100];
    int i = 0;
    while (n > 0)
    {
        bin[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%d", bin[j] * 2);
    printf("\n");
}

int main()
{
    ll u t;
    scanf("%lld", &t);

    ans(t);
}