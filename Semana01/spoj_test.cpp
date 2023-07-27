/*
    COMPLEXITY(big O): 
        time: O(n) - n is number of inputs before a 42
		space: O(1)

    DESCRIPTION:
	 Search for the answer to life :)	
*/
#include <iostream>

int main()
{
    int cur;

    while (1)
    {
        scanf("%d", &cur);
        if (cur == 42)
            break;
        else
            printf("%d\n", cur);
    }
}
