/*
    COMPLEXITY(big O):
        time:
        space:

    DESCRIPTION:

*/

#include <iostream>
#include <string.h>

#define ll long long
#define u unsigned
#define nl std::endl
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x > y ? y : x)

#define MAXN 1000000000
int a, n;
bool done[MAXN];
int swich(int t)
{
    if (t < 10 || t % 10 == 0)
        return -1;

    int arr[7], i;
    memset(arr, 0, sizeof arr);
    for (i = 6; t > 10; i--)
    {
        arr[i] = t % 10;
        t /= 10;
    }
    arr[i] = arr[6];
    arr[6] = t;

    int sum = 0;
    for (int i = 0; i < 7; i++)
    {
        sum *= 10;
        sum += arr[i];
    }
    return sum;
}

int doStuff(int smt, int trys)
{
    if (smt > n * 10 || smt < 0 || smt > MAXN)
        return -1;
    if (smt == n)
        return trys;
    if (done[smt])
        return -1;

    done[smt] = 1;
    int ta = doStuff(smt * a, trys + 1);
    int ts = doStuff(swich(smt), trys + 1);
    if (ta > 0 && ts > 0)
        return MIN(ta, ts);
    return MAX(ta, ts);
}
int main()
{
    memset(done, 0, sizeof done);
    scanf("%d %d", &a, &n);
    printf("%d\n", doStuff(1, 0));
}