#include <iostream>
#include <map>

#define ll long long
#define u unsigned
#define nl std::endl;

int main()
{
    int t, n, count, max, last;
    std::cin >> t;
    std::map<int, int> flakes;

    while (t--)
    {
        std::cin >> n;
        flakes.clear();
        count = 0, max = 0, last = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            std::cin >> a;
            auto key = flakes.find(a);

            if (key != flakes.end())
            {
                if (key->second < last)
                    count = i - last;
                else
                    count = i - key->second;

                if (key->second > last)
                    last = key->second;
                key->second = i;

                // printf("debug - i = %d,a = %d , count = %d, max = %d ,last = %d,found repeated\n", i, a, count, max, last);
            }
            else
            {
                flakes.insert({a, i});
                count++;
                // printf("debug - i = %d,a = %d , count = %d, max = %d ,last = %d,\n", i, a, count, max, last);
            }
            if (max < count)
                max = count;
        }
        std::cout << max << nl;
    }
}