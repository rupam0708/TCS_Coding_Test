#include <iostream>
#include <vector>
using namespace std;

vector<int> get_all_leaders(vector<int> v)
{
    int i = 0, j = 0, n = v.size();
    vector<int> res;
    while (i < n)
    {
        j = i;
        while (j < n)
        {
            if (v[i] < v[j])
            {
                j = -1;
                break;
            }
            j++;
        }
        if (j != -1)
            res.push_back(v[i]);
        i++;
    }
    return res;
}

vector<int> get_all_leaders_2(vector<int> v)
{
    int n = v.size(), max_ele = v[n - 1];
    vector<int> res;
    res.push_back(v[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] >= max_ele)
        {
            res.push_back(v[i]);
            max_ele = v[i];
        }
    }

    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    int n;

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << endl;

    vector<int> leaders = get_all_leaders(v);

    for (int l : leaders)
        cout << l << " ";
    cout << endl;

    leaders = get_all_leaders_2(v);

    for (int l : leaders)
        cout << l << " ";
    cout << endl;

    return 0;
}