#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define ll long long
#define u unsigned
#define nl std::endl;
bool customSort(std::pair<int, std::pair<int, int>> a, std::pair<int, std::pair<int, int>> b)
{
    if (a.second.first > b.second.first)
        return true;
    if (a.second.first == b.second.first)
        return a.second.second < b.second.second;
    return false;
}
int main()
{
    int n, c, x, pos = 1;
    std::cin >> n >> c;
    std::map<int, int> repetitions, position;
    std::vector<std::pair<int, std::pair<int, int>>> end;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        if (repetitions[x] == 0)
            repetitions[x] = 1;
        else
            repetitions[x]++;

        if (position[x] == 0)
            position[x] = pos++;
    }

    for (auto it = repetitions.begin(); it != repetitions.end(); it++)
        end.push_back({it->first, {it->second, position[it->first]}});

    std::sort(end.begin(), end.end(), customSort);

    for (int i = 0; i < end.size(); i++)
        for (int j = 0; j < end[i].second.first; j++)
            std::cout << end[i].first << " ";
    std::cout << nl;
}