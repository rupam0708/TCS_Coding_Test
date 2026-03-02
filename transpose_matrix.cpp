#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;

    vector<vector<int>> m(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> m[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << m[i][j];
        }
        cout << endl;
    }

    cout << "Transposed: " << endl;

    for (int j = 0; j < c; j++)
    {
        for (int i = 0; i < r; i++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}