#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    vector<vector<int>> matrix = {{1, 2}, {2, 1}, {3, 4}, {4, 5}, {5, 4}};
    unordered_map<int, int> mp;
    int first, second;

    for (int i = 0; i < matrix.size(); i++)
    {
        first = matrix[i][0];
        second = matrix[i][1];

        if (mp.find(second) != mp.end() && mp[second] == first)
        {
            cout << "(" << first << "," << second << ") ";
        }
        else
        {
            mp[first] = second;
        }
    }
    cout << endl;

    return 0;
}