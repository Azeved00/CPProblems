#include <iostream>
#include <vector>
#include <string>

#define ll long long
#define u unsigned
#define nl std::endl

#define MAX 100000

// Binary search (note boundaries in the caller)
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
void LIS(std::vector<int> &v)
{
    if (v.size() == 0)
        return;

    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail

    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++)
    {
        for (int i = 0; i < length; i++)
            std::cout << tail[i] << " ";
        std::cout << nl;

        // new smallest value
        if (v[i] < tail[0])
            tail[0] = v[i];

        // v[i] extends largest subsequence
        else if (v[i] > tail[length - 1])
            tail[length++] = v[i];

        // v[i] will become end candidate of an existing
        // subsequence or Throw away larger elements in all
        // LIS, to make room for upcoming greater elements
        // than v[i] (and also, v[i] would have already
        // appeared in one of LIS, identify the location
        // and replace it)
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
    }
    printf("Max hits: %d\n", length);
    for (int i = 0; i < length; i++)
        std::cout << tail[i] << nl;
}

int main()
{
    int t;
    scanf("%d", &t);
    std::string s;
    // with my aprroach i need to read 2 lines so that the input is read correctly
    std::getline(std::cin, s);
    std::getline(std::cin, s);
    while (t--)
    {
        std::vector<int> v;

        while (std::getline(std::cin, s) && s != "")
            v.push_back(std::stoi(s));

        LIS(v);
        if (t != 0)
            std::cout << nl;
    }
}