/*
    COMPLEXITY(big O):
        time: n
        space: n (2n)

    DESCRIPTION:
		while reading input save both  the position and number of occurenc
		output is simply trying to find number in map
*/

#include <iostream>
#include <string.h>
#include <map>
#include <array>

#define ll long long
#define u unsigned
#define nl std::endl
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x > y ? y : x)

#define pair std::array<int, 2>
#define MAXN 100000

std::map<int, int> times;
std::map<pair, int> pos;

int main()
{
    int n, q;
    int a, b;
    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);

        auto key = times.find(a);

        if (key != times.end())
            key->second++;
        else
            times.insert({a, 1});

        b = times[a];
        pos[{b, a}] = i + 1;
    }

    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &a, &b);
        if (pos.find({b, a}) != pos.end())
            printf("%d\n", pos[{b, a}]);
        else
            printf("-1\n");
    }
}
