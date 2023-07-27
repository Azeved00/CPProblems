#include <iostream>
#include <string.h>
#include <math.h>

#define ll long long
#define u unsigned
#define nl std::endl
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x > y ? y : x)

#define MAXN
int points[105][2];
double calcDist(int p1, int p2)
{
    return sqrt((points[p1][0] - points[p2][0]) * (points[p1][0] - points[p2][0]) + (points[p1][1] - points[p2][1]) * (points[p1][1] - points[p2][1]));
}
int main()

{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &points[i][0], &points[i][1]);

    double max;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            double a = calcDist(i, j);
            max = MAX(a, max);
        }

    printf("%.10f\n", max);
}