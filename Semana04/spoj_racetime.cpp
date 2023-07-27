#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long
#define u unsigned
#define nl std::endl
#define MAX 100005

int n;
int sqt;
int val[MAX];
std::vector<int> sorted[320];
// got TLE... probably to many divisions
// use the same technic as a merge sort tree
// in the block store a sorted array to witch i can use upper bound to get the ans
int query(int l, int r, int x) // query logic
{
    int ans = 0;
    int lb = l / sqt, rb = r / sqt;

    if (lb == rb) // in  the same block
    {
        for (int i = l; i <= r; i++)
            if (val[i] <= x)
                ans++;
    }
    else
    {
        for (int i = lb * sqt + sqt - 1; i >= l; i--) // left most block
            if (val[i] <= x)
                ans++;
        for (int i = lb + 1; i < rb; i++) // the blocks in the middle
            ans += (upper_bound(sorted[i].begin(), sorted[i].end(), x) - sorted[i].end());
        for (int i = rb * sqt; i <= r; i++) // right most block
            if (val[i] <= x)
                ans++;
    }
    return ans;
}

void update(int pos, int x) // do update logic
{
    int block = pos / sqt;
    // determine at wich position in the sorted array the old value was ans substitute it
    // same "trick" as what we do to count the numbers that are inside the block
    int idx = std::lower_bound(sorted[block].begin(), sorted[block].end(), val[pos]) - sorted[block].begin();
    val[pos] = x;
    sorted[block][idx] = x;
    // resort the array
    std::sort(sorted[block].begin(), sorted[block].end());
}

int main()
{
    int q, a, b, c;
    char op;
    std::cin >> n >> q;

    sqt = (int)sqrt(n + .0) + 1; // size of the block and the number of blocks

    // read the values int val and create the max
    for (int pos = 0; pos < n; pos++)
    {
        std::cin >> val[pos];
        // input to the block
        sorted[pos / sqt].push_back(val[pos]);
    }
    for (int a = 0; a <= sqt; a++)
        std::sort(sorted[a].begin(), sorted[a].end());

    // read the queries
    while (q--)
    {
        std::cin >> op;
        if (op == 'C')
        {
            std::cin >> a >> b >> c;
            std::cout << query(a - 1, b - 1, c) << nl;
        }
        else
        {
            std::cin >> a >> b;
            update(a - 1, b);
        }
    }
}
