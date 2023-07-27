#include <iostream>

#define ll long long
#define u unsigned
#define nl std::endl

#define MAX 400005

// since it starts off as everithing turned down (a 0)
// we dont need to build a tree, we just need to have an array with everithing as a 0
// learned algorith from https://iq.opengenus.org/lazy-propagation-in-segment-tree/

int segtree[MAX];
bool lazy[MAX];

int query(int pos, int start, int end, int a, int b)
{
    // out of bounds check
    if (start > end || a > end || b < start)
        return 0;

    // lazy check
    if (lazy[pos])
    {
        // update this pos
        lazy[pos] = false;
        segtree[pos] = (end - start + 1) - segtree[pos];

        // update children
        if (start < end)
        {
            lazy[pos * 2] = !lazy[pos * 2];
            lazy[pos * 2 + 1] = !lazy[pos * 2 + 1];
        }
    }

    // inside range check
    if (a <= start && end <= b)
        return segtree[pos];

    // else go to children
    int mid = (start + end) / 2;
    int left = query(pos * 2, start, mid, a, b);
    int right = query(pos * 2 + 1, mid + 1, end, a, b);
    return left + right;
}

void update(int pos, int start, int end, int a, int b)
{
    // lazy check (copy)
    if (lazy[pos])
    {
        // update this pos
        lazy[pos] = false;
        segtree[pos] = (end - start + 1) - segtree[pos];

        // update children
        if (start < end)
        {
            lazy[pos * 2] = !lazy[pos * 2];
            lazy[pos * 2 + 1] = !lazy[pos * 2 + 1];
        }
    }

    // out of bounds again
    if (start > end || a > end || b < start)
        return;

    // inside range
    if (a <= start && end <= b)
    {
        // update pos and children
        segtree[pos] = (end - start + 1) - segtree[pos];
        if (start < end)
        {
            lazy[pos * 2] = !lazy[pos * 2];
            lazy[pos * 2 + 1] = !lazy[pos * 2 + 1];
        }
        return;
    }

    // else update children
    int mid = (start + end) / 2;
    update(pos * 2, start, mid, a, b);
    update(pos * 2 + 1, mid + 1, end, a, b);

    // propagation
    if (start < end)
        segtree[pos] = segtree[pos * 2] + segtree[pos * 2 + 1];
}

int main()
{
    int n, m, op, a, b;
    std::cin >> n >> m;

    while (m--)
    {
        std::cin >> op >> a >> b;

        if (op == 1)
            std::cout << query(1, 1, n, a, b) << nl; // Range Sum Query
        else
            update(1, 1, n, a, b); // Range change
    }
}