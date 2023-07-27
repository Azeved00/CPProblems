/*
    COMPLEXITY(big O): 
        time: test cases * O(reverse)
		space: O(1)

    DESCRIPTION:
		read 2 numbers 
		reverse them 
		add them 
		reverse the sum
*/
#include <iostream>

//O(number of digits(of num))
int reverse(int num)
{
    int rev = 0;
    while (num != 0)
    {
        rev *= 10;
        rev += num % 10;
        num /= 10;
    }
    return rev;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", reverse(reverse(a) + reverse(b)));
    }
}
