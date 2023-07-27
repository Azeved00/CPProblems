/*
    COMPLEXITY(big O):
        time: mtrxSize * wordSize
        space:

    DESCRIPTION:
        transform dictionary into trie
        do one DFS on the mtrx
        for each "node" chech place in trie
        if possible to go deeper into the trie go
        else skip the node

*/

#include <iostream>
#include <string.h>

#define ll long long
#define u unsigned
#define nl std::endl
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x > y ? y : x)
#define set0(a) memset(a, 0, sizeof a)

#define MAXN 105
struct node
{
    int score;
    bool used = 0;
    node *children[28];
};

int mtrx[6][6];
bool checked[6][6];
int ans;

// O(wordSize)
void tryWord(int posX, int posY, node *now)
{
    now = now->children[mtrx[posX][posY]];
    if (now == __null || checked[posX][posY])
        return;

    checked[posX][posY] = 1;
    if (!now->used && now->score > 0)
    {
        now->used = 1;
        ans += now->score;
    }

    tryWord(posX + 1, posY + 0, now);
    tryWord(posX + 0, posY + 1, now);
    tryWord(posX - 1, posY + 0, now);
    tryWord(posX + 0, posY - 1, now);
    tryWord(posX - 1, posY + 1, now);
    tryWord(posX + 1, posY - 1, now);
    tryWord(posX - 1, posY - 1, now);
    tryWord(posX + 1, posY + 1, now);
    checked[posX][posY] = 0;
}

node *newNode(void)
{
    node *newN = new node;
    newN->score = 0;
    newN->used = 0;
    for (int i = 0; i < 28; i++)
        newN->children[i] = __null;
    return newN;
}

void reset()
{
    scanf("%*c");
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            mtrx[i][j] = 27;
    ans = 0;
}

int main()
{
    int t;
    scanf("%d%*c", &t);
    for (int tc = 1; tc <= t; tc++)
    {
        reset();
        node *root = newNode();
        int words;

        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                char temp;
                scanf("%c", &temp);
                mtrx[i][j] = temp - 'A';
            }
            scanf("%*c");
        }

        scanf("%d%*c", &words);
        for (int i = 0; i < words; i++)
        {
            int wordSize = 0;
            char temp;
            node *now = root;

            while (scanf("%c", &temp) != EOF && temp != '\n')
            {
                if (now->children[temp - 'A'] == __null)
                {
                    node *newT = newNode();
                    now->children[temp - 'A'] = newT;
                }
                now = now->children[temp - 'A'];
                wordSize++;
            }

            now->score += 1 * (wordSize < 5);
            now->score += 2 * (wordSize == 5);
            now->score += 3 * (wordSize == 6);
            now->score += 5 * (wordSize == 7);
            now->score += 11 * (wordSize > 7);
        }

        // go trough matrix
        for (int i = 1; i < 5; i++)
            for (int j = 1; j < 5; j++)
                tryWord(i, j, root);

        printf("Score for Boggle game #%d: %d\n", tc, ans);
    }
}