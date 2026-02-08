#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main()
{
    vector<int> v = {10, 5, 10, 15, 10, 5};
    unordered_map<int, int> mp;

    for (int val: v)
    {
        mp[val]++;
    }

    for(auto val : mp)
    {
        cout << val.first << " -> " << val.second << endl;
    }

    return 0;
}