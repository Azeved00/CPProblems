/*
    COMPLEXITY(big O):
        time: n
        space: n

    DESCRIPTION:
		go trough all input
		find input  that is higher or equal than the next input
*/

#include <iostream>
#include <string.h>

#define ll long long
#define u unsigned
#define nl std::endl
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x > y ? y : x)

#define MAXN 100000
int arr[MAXN];
int n;


//O(n)
int platformer()
{
    int i;
    for (i = 0; i < n - 1; i++)
        if (arr[i] >= arr[i + 1])
            break;
    
    return arr[i];
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", platformer());
}
