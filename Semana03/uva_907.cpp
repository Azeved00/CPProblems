#include <iostream>
#include <queue>
#include <map>
#include <string>

#define ll long long
#define u unsigned
#define nl std::endl;

int A[605], n, m;
// bool d;
int check(int res)
{
    int sum = 0, cnt = 0, i;
    for (i = 0; i < n; i++)
    {
        if (A[i] > res)
            return 0;
        if (sum + A[i] > res)
            sum = A[i], cnt++;
        else
            sum += A[i];
        // printf("deubg - check - A[%d] = %d,sum = %d, cnt = %d \n", i, A[i], sum, cnt);
    }
    if (sum)
        cnt++;
    // printf("deubg - check -sum = %d, cnt = %d \n", sum, cnt);

    return cnt <= m;
}
int main()
{
    int i;
    while (std::cin >> n >> m)
    {
        // printf("deubg - n = %d, m = %d \n", n, m);
        n++, m++;
        for (i = 0; i < n; i++)
            scanf("%d", &A[i]);
        // printf("deubg - read array\n");

        int l = 0, r = 1000000, mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            // printf("deubg - l = %d, mid = %d, r = %d\n", l, mid, r);
            // d = check(mid);
            // printf("deubg - check (mid) = %d\n", d);

            if (check(mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        printf("%d\n", r + 1);
    }
    return 0;
}
// 4 3 7 2 6 4 5
