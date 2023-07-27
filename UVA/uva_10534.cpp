#include <iostream>
#include <vector>
#include <cstring>

#define ll long long
#define u unsigned
#define nl std::endl
#define p_ii std::pair<int, int>

#define MAX 10000

int n, res1[MAX], res2[MAX];
int CeilIndex(std::vector<int> &v, int l, int r, int key)
{
    while (r - l > 1)
    {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}
void LIS(int range, int arr[], int flag) // do LIS until certain point of arr O(nlog n)
{
    std::vector<int> tail(range, 0);
    int length = 1; // always points empty slot in tail
    tail[0] = arr[0];
    for (int i = 1; i < range; i++)
    {
        /* debug
        for (int i = 0; i < length; i++)
            std::cout << tail[i] << " ";
        std::cout << nl;*/

        // new smallest value
        if (arr[i] < tail[0])
            tail[0] = arr[i];

        // v[i] extends largest subsequence
        else if (arr[i] > tail[length - 1])
            tail[length++] = arr[i];

        // v[i] will become end candidate of an existing
        // subsequence or Throw away larger elements in all
        // LIS, to make room for upcoming greater elements
        // than v[i] (and also, v[i] would have already
        // appeared in one of LIS, identify the location
        // and replace it)
        else
            tail[CeilIndex(tail, -1, length - 1, arr[i])] = arr[i];

        if (flag)
            res1[i] = length;
        else
            res2[i] = length;
    }
}

int main()
{

    while (scanf("%d", &n) == 1)
    {
        memset(res1, 0, sizeof res1);
        memset(res2, 0, sizeof res2);
        int val[MAX], rval[MAX], max = 1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &val[i]);
            rval[n - i - 1] = val[i]; // getting reversed of val
        }

        LIS(n, val, 1);
        LIS(n, rval, 0);

        for (int i = 1; i < n; i++)
        {
            int a = res1[i];     // do lis from left until i
            int b = res2[n - i]; // lis  from right until i
            // printf("i = %d : %d %d\n", i, a, b);
            //     if lis from left has the same elements as lis from the right
            //     then a wavio sequence is possible
            //     we want the maximun wavio sequence
            if (a == b && a > max)
                max = a;
        }

        printf("%d\n", 2 * max - 1);
    }
}