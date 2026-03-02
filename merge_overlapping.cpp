#include <iostream>
#include <vector>
using namespace std;

vector<int> max_ele_in_ksize(vector<int> v, int k)
{
    vector<int> res;
    int temp = -1;
    for (int i = 0; i < v.size() - (k - 1); i++)
    {
        for (int j = i; j < i + k; j++)
        {
            temp = max(temp, v[j]);
        }
        res.push_back(temp);
        temp = -1;
    }

    return res;
}

vector<vector<int>> merge_overlapping(vector<vector<int>> v)
{
    vector<vector<int>> res;
    int max_ele;

    sort(v.begin(), v.end());

    res.push_back(v[0]);

    for (int i = 1; i < v.size(); i++)
    {
        vector<int> &last = res.back();
        vector<int> &curr = v[i];

        if (curr[0] <= last[1])
            last[1] = max(last[1], curr[1]);
        else
            res.push_back(curr);
    }

    return res;
}

int main()
{
    vector<int> res = max_ele_in_ksize({1, 3, -1, -3, 5, 3, 6, 7}, 3);
    for (int val : res)
        cout << val << " ";
    cout << endl;
    return 0;
}