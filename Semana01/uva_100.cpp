/*
    COMPLEXITY(big O): 
        time: O(n) - n is number of numbers needed to reach 1
		space: O(1)

    DESCRIPTION:
		simulate the sequence	
*/

#include <iostream>

int main()
{
    int i, a, j, c, cur, max, atual;

    while (true)
    {
        max = 0;

        if (scanf("%d %d", &i, &j) == -1)
            break;
        if (i > j)
        {
            atual = j;
            c = i;
        }
        else
        {
            atual = i;
            c = j;
        }
        for (atual; atual <= c; atual++)
        {
            a = atual;
            cur = 0;

            while (1)
            {
                cur++;

                if (a % 2 == 0)
                    a /= 2;
                else if (a == 1)
                    break;
                else
                    a = (3 * a + 1);
            }
            if (cur > max)
                max = cur;
        }

        printf("%d %d %d\n", i, j, max);
    }
}
