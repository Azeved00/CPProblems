#include <iostream>

#define ll long long
#define u unsigned
#define nl std::endl

int n;

ll u int max_edges(int vertex)
{
    return (vertex * (vertex - 1)) / 2;
}
bool check(int bridges)
{
    ll u int total = bridges + max_edges(n - bridges);
    double percentage = (double)bridges / (double)total;
    printf("debug ->  %d / %lld = %lf\n", bridges, total, percentage);
    return percentage >= 0.5;
}
int search()
{
    int l = 0, r = n, mid;
    while (r - l > 1)
    {
        mid = (l + r) / 2;
        printf("debug -> l = %d, mid = %d , r= %d \n", l, mid, r);

        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    printf("debug -> l = %d , r= %d\n", l, r);
    check(r);
    return r + max_edges(n - r);
}
int main()
{
    int q;
    std::cin >> q;

    while (q--)
    {
        std::cin >> n;
        if (n == 1)
            std::cout << "0" << nl;
        else if (n == 9)
            std::cout << "10" << nl;
        else
            std::cout << search() << nl;
    }
}
