#include <iostream>
#include <queue>
#include <map>
#include <string>

#define ll long long
#define u unsigned
#define nl std::endl;

int main()
{
    std::string t;
    int num, interval, count;
    std::priority_queue<
        std::pair<int, std::pair<int, int>>,
        std::vector<std::pair<int, std::pair<int, int>>>,
        std::greater<std::pair<int, std::pair<int, int>>>>
        queue;

    while (std::cin >> t && t != "#")
    {
        std::cin >> num >> interval;
        queue.push(std::make_pair(interval, std::make_pair(num, interval)));
    }

    std::cin >> count;
    while (count--)
    {
        auto top = queue.top();
        std::cout << top.second.first << std::endl;
        queue.push(std::make_pair(top.first + top.second.second, std::make_pair(top.second.first, top.second.second)));
        queue.pop();
    }
}