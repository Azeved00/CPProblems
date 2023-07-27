#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

#define ll long long
#define u unsigned
#define nl std::endl
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x > y ? y : x)

#define MAXN 500005

int arr[MAXN];
std::vector<int> order;
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int i = 0;
    for (; i < k; i++)
        order.push_back(arr[i]);
    std::sort(order.begin(), order.end(), std::greater<int>());
    printf("%d\n", order[k - 1]);

    for (; i < n; i++)
    {
        order.push_back(arr[i]);
        std::sort(order.begin(), order.end(), std::greater<int>());

        printf("%d\n", order[k - 1]);
    }
}