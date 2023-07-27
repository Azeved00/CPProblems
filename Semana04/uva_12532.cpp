#include <iostream>
#include <cstring>

#define ll long long
#define u unsigned
#define nl std::endl

#define MAX 100005
int n;           // Number of elements in the segtree
int v[MAX];      // Array of values
int st[4 * MAX]; // Segtree (in this case storing interval sums)

// isnt this one easier then the first one ?
// actually just changed so little haha, thank you for pseudo code <3

// Merge contents of nodes a and b
int merge(int a, int b)
{
    return a * b;
}

// Build initial segtree (in position pos, interval [start,end])
void build(int pos, int start, int end)
{
    if (start == end)
    {
        st[pos] = v[start];
    }
    else
    {
        int middle = start + (end - start) / 2;

        build(pos * 2, start, middle);
        build(pos * 2 + 1, middle + 1, end);

        st[pos] = merge(st[pos * 2], st[pos * 2 + 1]);
    }
    // printf("building: pos = %d,inside = %d\n", pos, st[pos]);
}

// Update node x to value r
void update(int pos, int start, int end, int x, int r)
{
    if (start > x || end < x)
        return;
    if (start == end && start == x)
    {
        st[pos] = r;
    }
    else
    {
        int middle = start + (end - start) / 2;
        update(pos * 2, start, middle, x, r);
        update(pos * 2 + 1, middle + 1, end, x, r);
        st[pos] = merge(st[pos * 2], st[pos * 2 + 1]);
    }
}

// Make a query of interval [x,y]
int query(int pos, int start, int end, int x, int y)
{
    if (start > y || end < x)
        return 1;
    if (start >= x && end <= y)
        return st[pos];

    int middle = start + (end - start) / 2;

    int a = query(pos * 2, start, middle, x, y);
    int b = query(pos * 2 + 1, middle + 1, end, x, y);

    return merge(a, b);
}

int main()
{
    char op;
    int q;
    while (std::cin >> n)
    {
        std::cin >> q;
        for (int i = 1; i <= n; i++)
        {
            int a;
            std::cin >> a;
            if (a < 0)
                v[i] = -1;
            else if (a > 0)
                v[i] = 1;
            else
                v[i] = 0;
        }

        build(1, 1, n);

        while (q--)
        {
            int a, b;
            std::cin >> op >> a >> b;
            if (op == 'P')
            {
                int res = query(1, 1, n, a, b);
                if (res > 0)
                    std::cout << "+";
                else if (res < 0)
                    std::cout << "-";
                else
                    std::cout << "0";
            }
            else
            {
                if (b < 0)
                    update(1, 1, n, a, -1);

                else if (b > 0)
                    update(1, 1, n, a, 1);

                else
                    update(1, 1, n, a, 0);
            }
        }
        std::cout << nl;
    }
    return 0;
}