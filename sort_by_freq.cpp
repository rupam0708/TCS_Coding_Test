#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>
using namespace std;

int main()
{
    unordered_map<int, int> freq_map;
    vector<int> v = {1, 2, 3, 2, 4, 3, 1, 2};

    for (int val : v)
        freq_map[val]++;

    auto cmp = [&](int a, int b)
    {
        if (freq_map[a] != freq_map[b])
            return freq_map[a] > freq_map[b];
        return a < b;
    };

    sort(v.begin(), v.end(), cmp);

    for (int val : v)
        cout << val << " ";
    cout << endl;

    return 0;
}