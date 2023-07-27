#include <iostream>
#include <queue>
#include <stack>

#define ll long long
#define u unsigned
#define nl std::endl;

int main()
{
    int n, c, x;
    while (std::cin >> n)
    {
        bool check[3] = {true, true, true};
        std::priority_queue<int> p;
        std::stack<int> s;
        std::queue<int> q;

        for (int i = 0; i < n && std::cin >> c >> x; i++)
        {

            if (c == 1)
            {
                p.push(x);
                s.push(x);
                q.push(x);
            }
            else if (c == 2)
            {
                if (p.empty() || p.top() != x)
                    check[0] = false;
                if (!p.empty())
                    p.pop();

                if (s.empty() || s.top() != x)
                    check[1] = false;
                if (!s.empty())
                    s.pop();

                if (q.empty() || q.front() != x)
                    check[2] = false;
                if (!q.empty())
                    q.pop();
            }
        }

        if (check[0] + check[1] + check[2] > 1)
            printf("not sure\n");
        else if (check[0])
            printf("priority queue\n");
        else if (check[1])
            printf("stack\n");
        else if (check[2])
            printf("queue\n");
        else
            printf("impossible\n");
    }
    return 0;
}