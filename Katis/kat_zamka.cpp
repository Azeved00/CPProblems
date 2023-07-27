/*
    COMPLEXITY(big O):
        time: O( (end - strt )* size_of_nunber)
		space: O(1)

    DESCRIPTION:
		start from left side and go up while trying to find goal
		start from right side and go down while trying to find goal
		worst case is the goal does not exist an so they go from start to end twice
*/
#include <iostream>

//O(size of the number)
int digit_sum(int num)
{
    int sum = 0;
    while (num != 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main()
{
    int str, end, goal;
    int i;

    scanf("%d %d %d", &str, &end, &goal);

    for (i = str; i <= end; i++)
        if (digit_sum(i) == goal)
        {
            printf("%d\n", i);
            break;
        }

    for (i = end; i >= str; i--)
        if (digit_sum(i) == goal)
        {
            printf("%d\n", i);
            break;
        }
}
