#include <iostream>
#include <map>
#include <array>
#include <bits/stdc++.h>

#define ll long long
#define u unsigned

typedef std::array<u int, 5> course;

int main()
{
    int n, max, nmax;
    course arr;
    while (scanf("%d", &n), n != 0)
    {
        max = 1;
        nmax = 0;
        std::map<course, int> val;

        while (n--)
        {
            scanf("%d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
            std::sort(arr.begin(), arr.end());

            auto key = val.find(arr);

            if (key != val.end())
                key->second++;
            else
                val.insert({arr, 1});
        }

        for (auto &i : val)
            if (i.second > max)
            {
                max = i.second;
                nmax = i.second;
            }
            else if (i.second == max)
                nmax += i.second;

        printf("%d\n", nmax);
    }
}