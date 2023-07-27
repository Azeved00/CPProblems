#include <iostream>
#include <set>

#define ll long long
#define u unsigned

int main()
{
    int n;

    while (std::cin >> n, n != 0)
    {
        std::multiset<int> urn;

        ll u int t = 0;
        while (n--)
        {
            int k;
            std::cin >> k;
            for (int i = 0; i < k; i++)
            {
                int a;
                std::cin >> a;
                urn.insert(a);
            }

            auto ue = --(urn.end()), ub = urn.begin();
            t += *ue - *ub;
            // printf("%d - %d = %d\nt=%d\n", *ue, *ub, *ue - *ub, t);

            urn.erase(ub);
            urn.erase(ue);
        }
        std::cout << t << std::endl;
    }
}