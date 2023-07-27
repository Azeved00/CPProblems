#include <iostream>
#include <string.h>

#define ll long long
#define u unsigned
#define nl std::endl

#define MAX (1024 + 5)

int bit[MAX][MAX];
int n;

int read(int x, int y)
{
    int sum = 0;
    for (int ax = x; ax > 0; ax -= (ax & -ax))
        for (int ay = y; ay > 0; ay -= (ay & -ay))

            sum += bit[ax][ay];

    return sum;
}
void update(int x, int y, int v)
{
    for (int ax = x; ax <= MAX; ax += (ax & -ax))
        for (int ay = y; ay <= MAX; ay += (ay & -ay))
            bit[ax][ay] += v;
}
int query(int x1, int y1, int x2, int y2)
{
    int ans = 0;

    ans += read(x2, y2);
    ans -= read(x1 - 1, y2);
    ans -= read(x2, y1 - 1);
    ans += read(x1 - 1, y1 - 1);

    return ans;
}

int main()
{
    int t;
    char op[3];
    scanf("%d", &t);

    while (t--)
    {
        memset(bit, 0, sizeof(bit));

        scanf("%d", &n);
        while (scanf("%s", op))
        {
            if (!strcmp(op, "SUM"))
            {
                int x1, x2, y1, y2;
                // get sum from (x1,y1) to (x2,y2)
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                printf("%d\n", query(x1 + 1, y1 + 1, x2 + 1, y2 + 1));
            }
            else if (!strcmp(op, "SET"))
            {
                int x1, y1, v;
                // set int (x1,y1) to v
                scanf("%d %d %d", &x1, &y1, &v);
                update(x1 + 1, y1 + 1, v - query(x1 + 1, y1 + 1, x1 + 1, y1 + 1));
            }
            else
                break;
        }
    }
}