#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define u unsigned
#define nl std::endl
#define MAX 30000

// merge sort trees wich is a variant of a segment tree
// but in each node of the tree there is a vector that stores the sorted array between positions
// code from https://www.geeksforgeeks.org/merge-sort-tree-smaller-or-equal-elements-in-given-row-range/

std::vector<int> segtree[4 * MAX + 5]; // the actuall tree

// build the tree while getting the input
void buildTree(int idx, int ss, int se)
{
    // printf("building: pos = %d, start = %d, end=%d\n", idx, ss, se);

    // leaf node
    if (ss == se)
    {
        int a;
        std::cin >> a;
        segtree[idx].push_back(a);

        // for (int now : segtree[idx])
        //     printf(" leaf: %d \n", now);
        return;
    }

    int mid = (ss + se) >> 1;

    // build left tree
    buildTree(2 * idx, ss, mid);

    // build right
    buildTree(2 * idx + 1, mid + 1, se);

    // merging left and right child in sorted order
    // merge is here https://en.cppreference.com/w/cpp/algorithm/merge
    // back_inserter is here https://en.cppreference.com/w/cpp/iterator/back_inserter
    merge(segtree[2 * idx].begin(), segtree[2 * idx].end(),
          segtree[2 * idx + 1].begin(), segtree[2 * idx + 1].end(),
          back_inserter(segtree[idx]));
}

// from ss to se and value greater then k.
int query(int pos, int start, int end, int ss, int se, int k)
{
    // out of range check
    if (ss > end || start > se)
        return 0;

    // inside range return
    if (ss <= start && se >= end)
    {
        // binary search over the sorted std::vector to return count > X
        // upperbound funct is here : https://en.cppreference.com/w/cpp/algorithm/upper_bound
        return (segtree[pos].end() - upper_bound(segtree[pos].begin(), segtree[pos].end(), k));
    }

    // if not in the range then keep searching
    // first left subtree then right subtree and lastly porpagate the ans
    int mid = (start + end) >> 1;
    int a = query(2 * pos, start, mid, ss, se, k);
    int b = query(2 * pos + 1, mid + 1, end, ss, se, k);
    return a + b;
}

int main()
{
    int n, q;
    // Construct segment tree
    std::cin >> n;
    buildTree(1, 1, n);

    // do the querys
    std::cin >> q;
    int ss, se, k; // each query left right and value
    while (q--)
    {
        std::cin >> ss >> se >> k;
        std::cout << query(1, 1, n, ss, se, k) << nl;
    }

    return 0;
}