// ja tinha feito este ex antes (como da para ver no uva)
// porem perdi o codigo
// entao copiei de https://github.com/Diusrex/UVA-Solutions/blob/master/272%20TEX%20Quotes.cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string temp;
    bool isFirst(true);

    while (getline(cin, temp))
    {
        for (string::iterator iter = temp.begin(); iter != temp.end(); ++iter)
        {
            if (*iter == '"')
            {
                if (isFirst)
                    cout << "``";
                else
                    cout << "''";

                isFirst = !isFirst;
            }
            else
                cout << *iter;
        }
        cout << '\n';
    }
}