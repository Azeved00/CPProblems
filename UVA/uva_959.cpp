#include <iostream>
#include <string.h>

#define ll long long
#define u unsigned
#define nl std::endl
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x > y ? y : x)

#define NMAX 10000

int ma, md; // max accelaration mad deaccelatarion
int n;
int arr[NMAX + 5];

ll ddp(int pos, int acc)
{
    // acc cannot be lower than 0 or higher than the current tile max speed
    if (0 > acc || acc > arr[pos + 1])
        return NMAX;
    // pos cannot be lower than 0 or higher than n (max pos)
    if (pos >= n)
        return 1;

    printf("do dp in %d %d %d\n", pos, acc, arr[pos + 1]);

    int min = NMAX;
    for (int i = ma; i >= md; i--)
        if (i != 0)
            min = MIN(min, ddp(pos + acc, acc + i));

    return min;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d %d", &ma, &md);
        ma /= 10;
        md /= 10;

        int a, s;
        n = 1;
        while (scanf("%d %d", &a, &s) && a != 0 && s != 0)
        {
            s /= 10;
            while (a--)
                arr[n++] = s;
        }

        // for (int i = 1; i < n; i++)
        //     printf("%d ", arr[i]);

        printf("%lld\n", ddp(0, 0));
    }
}