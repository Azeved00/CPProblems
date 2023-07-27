#include <iostream>
#include <set>
#include <vector>

#define ll long long
#define u unsigned

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int b, sg, sb;
        std::multiset<int, std::greater<int>> green;
        std::multiset<int, std::greater<int>> blue;
        // input
        scanf("%d %d %d", &b, &sg, &sb);

        while (sg--)
        {
            int a;
            std::cin >> a;
            green.insert(a);
        }

        while (sb--)
        {
            int a;
            std::cin >> a;
            blue.insert(a);
        }
        // simulation

        /*
        tried to do this, didnt work (values were off by 1 or 2)
        re did simulation from scratch with vectors
        a litle more work, but it payed off
        for (int a = 0; a < b; a++)
        {
            if (green.empty() || blue.empty())
                break;

            auto ag = green.begin();
            auto ab = blue.begin();

            battle[a] = *ag - *ab;

            // printf("battle:%d\ngreen : %d\nblue  : %d\nremain: %d\n", a, *ag, *ab, battle[a]);
            green.erase(ag);
            blue.erase(ab);

            if (a == (b - 1))
            {
                for (; a >= 0; a--)
                    if (battle[a] > 0)
                        green.insert(battle[a]);
                    else if (battle[a] < 0)
                        blue.insert(-battle[a]);
            }
        }*/
        while (!(green.empty() || blue.empty()))
        {
            std::vector<int> gw, bw;
            int fights = std::min(b, (int)std::min(green.size(), blue.size()));
            for (int i = 0; i < fights; i++)
            {
                auto ag = green.begin(), ab = blue.begin();

                if (*ag > *ab)
                    gw.push_back(*ag - *ab);
                else if (*ab > *ag)
                    bw.push_back(*ab - *ag);

                green.erase(ag);
                blue.erase(ab);
            }
            for (auto i : gw)
                green.insert(i);
            for (auto i : bw)
                blue.insert(i);
        }

        // output
        if (green.empty() && blue.empty())
            printf("green and blue died\n");
        else if (green.empty())
        {
            printf("blue wins\n");
            for (auto i : blue)
                std::cout << i << std::endl;
        }
        else
        {
            printf("green wins\n");
            for (auto i : green)
                std::cout << i << std::endl;
        }
        if (t != 0)
            std::cout << std::endl;
    }
}
