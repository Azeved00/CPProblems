/*
    COMPLEXITY(big O):
        time: 1
        space: 1

    DESCRIPTION:
		Simple math
*/

#include <iostream>
#include <string.h>

#define ll long long
#define u unsigned
#define nl std::endl
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x > y ? y : x)

#define MAXN 100000

int main()
{
    char a;
    int sum = 0, x;
    for (int i = 0; i < 3; i++)
    {
        scanf("%c", &a);
        x = a - '0';
        sum += x + x * 10 + x * 100;
    }

    printf("%d\n", sum);
}
