#include <iostream>
#include <string.h>
#include <vector>

#define ll long long
#define u unsigned
#define nl std::endl

#define MAXW 100
#define MAXC 30

char a[MAXW + 5][MAXC + 2], b[MAXW + 5][MAXC + 2]; // the texts
int L[MAXW + 5][MAXW + 5];                         // matrix 100 by 100 (for every word in the text)
int la, lb;                                        // length of texts

void printsequence()
{
    /*for (int i = 0; i < lb; i++)
    {
        for (int j = 0; j < la; j++)
            printf("| %2d ", L[j][i]);
        printf("|\n");
    }*/
    std::vector<char *> ans;
    int val, px = la - 1, py = lb - 1;
    while (1)
    {
        val = L[px][py];
        if (val == 0)
            break;
        else if (val > L[px - 1][py] && val > L[px][py - 1]) // get letter and move diagonaly
        {
            // printf("%s ", a[px]);
            ans.push_back(a[px]);
            px--, py--;
        }
        else if (val <= L[px][py - 1])
            py--;
        else
            px--;
    }
    for (int i = L[la - 1][lb - 1] - 1; i >= 0; i--)
    {
        printf("%s", ans[i]);
        if (i)
            printf(" ");
        else
            printf("\n");
    }
}
void dist()
{
    for (int i = 0; i < la; i++)
        for (int j = 0; j < lb; j++)
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (!strcmp(a[i], b[j]))
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = std::max(L[i - 1][j], L[i][j - 1]);

    printsequence();
}

int main()
{

    while (scanf("%s", a[1]) == 1)
    {
        L[0][0] = 0;
        for (la = 2; scanf("%s", a[la]) && a[la][0] != '#'; la++)
            L[la][0] = la; // number of words in array a && set the first line of the matrix to [1..la]

        for (lb = 1; scanf("%s", b[lb]) && b[lb][0] != '#'; lb++)
            L[0][lb] = lb; // number of words in array b && set the first clun of the matrix to [1..lb]

        // printf("%d %d\n", la, lb);
        dist();
    }
}