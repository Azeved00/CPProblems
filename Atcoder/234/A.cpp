#include <iostream>
#include <string.h>

#define ll long long
#define u unsigned
#define nl std::endl
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x > y ? y : x)

int f(int x)
{
    return (x * x + 2 * x + 3);
}

int main()
{
    int t;
    scanf("%d", &t);
    printf("%d\n", f(f(f(t) + t) + f(f(t))));
}