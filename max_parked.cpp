#include <iostream>
#include <vector>
using namespace std;

int get_max_parked_row(int m, int n, vector<vector<int>> p)
{
    int parked = 0, temp = 0, res;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (p[i][j] == 1)
                temp++;
        }

        if (temp > parked)
        {
            parked = temp;
            res = i;
        }

        temp = 0;
    }

    return res + 1;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> p(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> p[i][j];
        }
    }

    cout << get_max_parked_row(m, n, p) << endl;
    return 0;
}