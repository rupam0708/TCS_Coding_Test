#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int removeDulicatesFromSorted(vector<int> v, int n)
{
    int i = 0, j = 1;
    while (j < n)
    {
        if (v[i] != v[j])
        {
            i++;
            v[i] = v[j];
        }
        j++;
    }
    return i;
}

vector<int> removeDulicatesFromUnSorted(vector<int> v, int n)
{
    unordered_map<int, bool> mp;
    vector<int> res;
    for (int val : v)
    {
        if (!mp[val])
        {
            res.push_back(val);
            mp[val] = true;
        }
    }

    return res;
}

vector<int> getDups(vector<int> v, int n)
{
    vector<int> res;
    unordered_map<int, int> mp;

    for (int val : v)
    {
        mp[val]++;
    }

    for (auto val : v)
    {

        if (mp[val] > 1)
        {
            res.push_back(val);
            mp[val] = 0;
        }
    }

    return res;
}

vector<int> getNonDups(vector<int> v, int n)
{
    vector<int> res;
    unordered_map<int, int> mp;

    for (int val : v)
    {
        mp[val]++;
    }

    for (auto val : v)
    {

        if (mp[val] == 1)
        {
            res.push_back(val);
            mp[val] = 0;
        }
    }

    return res;
}

int main()
{
    vector<int> v = {1, 1, 2, 2, 2, 3, 3};
    int n = v.size();
    int index = removeDulicatesFromSorted(v, n);
    for (int k = 0; k < index + 1; k++)
        cout << v[k] << " ";
    cout << endl;

    v = {2, 3, 1, 9, 3, 1, 3, 9};
    vector<int> res = removeDulicatesFromUnSorted(v, v.size());
    for (int val : res)
        cout << val << " ";
    cout << endl;

    v = {1, 1, 2, 3, 4, 4, 5, 2};
    res = getDups(v, v.size());
    for (int val : res)
        cout << val << " ";
    cout << endl;

    v = {1, 2, -1, 1, 3, 1};
    res = getNonDups(v, v.size());
    for (int val : res)
        cout << val << " ";
    cout << endl;

    return 0;
}