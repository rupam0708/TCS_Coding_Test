#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> replaceWithRank(vector<int> v, int n)
{
    vector<int> sorted = v;
    sort(sorted.begin(), sorted.end());
    unordered_map<int, int> rank_map;

    for (int i = 0; i < n; i++)
    {
        rank_map[sorted[i]] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        v[i] = rank_map[v[i]];
    }

    return v;
}

int main()
{
    vector<int> v = {20, 15, 26, 2, 98, 6};
    vector<int> replaced = replaceWithRank(v, v.size());
    for (int val : replaced)
        cout << val << " ";
    cout << endl;
    return 0;
}