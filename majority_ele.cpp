#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, int> get_freqs(vector<int> v)
{
    unordered_map<int, int> mp;
    for (int val : v)
        mp[val]++;

    return mp;
}

int get_majority_ele(vector<int> v)
{
    unordered_map<int, int> mp = get_freqs(v);
    int n = v.size();

    for (auto it : mp)
    {
        if (it.second >= n / 2)
            return it.first;
    }

    return -1;
}

int main()
{
    cout << get_majority_ele({1, 2, 3, 2, 3, 1, 1, 4, 1}) << endl;
    return 0;
}