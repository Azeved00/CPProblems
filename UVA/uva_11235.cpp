#include <iostream>
#include <vector>

#define ll long long
#define u unsigned
#define nl std::endl
#define MAX 100005
#define mpair std::pair<int, std::pair<int, int>>
// mpair number of repetitions and position at witch it beguins and ends
// looking to treat the continuos number as just one number

int n;                // number of elements in segtree
mpair stree[4 * MAX]; // Segtree
std::vector<mpair> val;

int max(int a, int b)
{
    if (a >= b)
        return a;
    return b;
}

// building the tree and getting the position of the blocks of the same number
void build(int pos, int start, int end)
{
    // printf("building: pos = %d, start = %d, end=%d\n", pos, start, end);
    if (start == end)
    {
        // assigning all the values of the pair to the tree
        stree[pos].first = val[start].first;
        stree[pos].second.first = val[start].second.first;
        stree[pos].second.second = val[start].second.second;
        // printf("building: pos = %d {%d{%d,%d}}\n", pos, stree[pos].first, stree[pos].second.first, stree[pos].second.second);
    }
    else
    {
        // standard tree building
        int middle = start + (end - start) / 2;
        build(pos * 2, start, middle);
        build(pos * 2 + 1, middle + 1, end);

        // we want the highest repetition
        stree[pos].first = max(stree[pos * 2].first, stree[pos * 2 + 1].first);
        // adding the spans
        // the minimun is the left leaf and the max is the right leaf
        stree[pos].second.first = stree[pos * 2].second.first;
        stree[pos].second.second = stree[pos * 2 + 1].second.second;
    }
}

// Make a query of interval [x,y]
int query(int pos, int x, int y)
{
    mpair &node = stree[pos];
    // printf("query: pos = %d {%d{%d,%d}}, x = %d ,y = %d\n", pos, node.first, node.second.first, node.second.second, x, y);

    if (node.second.first > y || node.second.second < x)
    {
        // printf("out of bounds\n");
        return 0; // for out of bound nodes
    }

    if (node.second.first >= x && node.second.second <= y)
    {
        // printf("returnd\n");
        return node.first; // returns the value if block is within x and y
    }

    if (stree[pos * 2].second.second == 0 && stree[pos * 2 + 1].second.second == 0)
    {
        bool flag = false;
        int R = node.second.second, L = node.second.first;

        // for when x or y is actually inside of a block
        // check if it is a leaf (block of same number)
        // check wich boud is inside
        // return repeated numbers

        // error with x and y being in the same block of numbers (thanks udebug)
        // using a flag is the best thing i can think of so we use it :)
        if (node.second.second > y)
        {
            flag = true;
            R = y;
            // printf("%d > %d\n", node.second.second, y);
        }
        if (x > node.second.first)
        {
            flag = true;
            L = x;
            // printf("%d > %d\n", x, L);
        }
        // printf("if flag return %d - %d + 1 = %d\n", R, L, R - L + 1);
        if (flag)
            return R - L + 1;
    }

    int a = query(pos * 2, x, y);
    int b = query(pos * 2 + 1, x, y);

    return max(a, b);
}

int main()
{
    int q;

    while (std::cin >> n && n != 0)
    {
        val.clear();
        int pos = 0, last = 1000000, a, rep = 0, total = 0;

        std::cin >> q;
        // taking care of input
        // grouping the same number as blocksin pairs(of tree) => (repetition, start_pos, end_pos)
        // printf("tree: n = %d , q = %d", n, q);
        for (int i = 0; i < n; i++)
        {
            std::cin >> a;
            if (a == last)
                rep++;
            else
            {
                val.push_back({rep, {pos - rep + 1, pos}});
                rep = 1;
                last = a;
                total++;
            }

            pos++;
        }
        val.push_back({rep, {pos - rep + 1, pos}});

        build(1, 1, total);

        while (q--)
        {
            int a, b;
            std::cin >> a >> b;
            // printf("%d,%d \n", a, b);
            std::cout << query(1, a, b) << nl;
        }
        // std::cout << "------------------------------------------------------" << nl;

        for (auto &i : stree)
            i = {0, {0, 0}};
    }
    // for (auto i : stree)
    //     printf("tree : number of times = %d, start = %d, end = %d \n", i.first, i.second.first, i.second.second);
}