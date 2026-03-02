#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int find_longest_balanced_subarray(vector<int> v)
{
    unordered_map<int, int> mp;
    int max_len = 0, curr_sum = 0;

    mp[0] = -1;

    for (int i = 0; i < v.size(); i++)
    {
        curr_sum += (v[i] == 1) ? 1 : -1;

        if (mp.find(curr_sum) != mp.end())
            max_len = max(max_len, i - mp[curr_sum]);
        else
            mp[curr_sum] = i;
    }

    return max_len;
}

int main()
{
    cout << find_longest_balanced_subarray({1, 0, 0, 1, 0, 1, 1}) << endl;
    return 0;
}