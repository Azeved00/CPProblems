#include <iostream>
#include <vector>
#include <string>

#define ll long long
#define u unsigned
#define nl std::endl

/*
i dont actually like this code bc
it uses a lot of space and time to do smth that could be done much more easily
but hey it got ac so we will roll and try to improve for the actual problems
*/

void printLIS(std::vector<int> &arr)
{
    printf("Max hits: %ld\n", arr.size());
    for (int x : arr)
        std::cout << x << nl;
}

void LIS(std::vector<int> arr)
{
    int n = arr.size();
    // L[i] - The longest increasing sub-sequence
    // ends with arr[i]
    std::vector<std::vector<int>> L(n);

    // L[0] is equal to arr[0]
    L[0].push_back(arr[0]);

    // start from index 1
    for (int i = 1; i < n; i++)
    {
        // do for every j less than i
        for (int j = 0; j < i; j++)
        {
            /* L[i] = {Max(L[j])} + arr[i]
            where j < i and arr[j] < arr[i] */
            if ((arr[i] > arr[j]) && (L[i].size() < L[j].size() + 1))
                L[i] = L[j];
        }

        // L[i] ends with arr[i]
        L[i].push_back(arr[i]);
    }

    // L[i] now stores increasing sub-sequence of
    // arr[0..i] that ends with arr[i]
    std::vector<int> max = L[0];

    // LIS will be max of all increasing sub-
    // sequences of arr
    for (std::vector<int> x : L)
        if (x.size() > max.size())
            max = x;

    // max will contain LIS
    printLIS(max);
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