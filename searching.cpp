#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> v, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] == k)
            return i;
    }

    return -1;
}

int binarySearch(vector<int> v, int n, int k)
{
    sort(v.begin(), v.end());
    int left = 0, right = n - 1, ans = -1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (v[mid] > k)
            right = mid - 1;
        else if (v[mid] < k)
            left = mid + 1;
        else
        {
            ans = mid;
            break;
        }
    }

    return ans;
}

bool isSubset(vector<int> v1, vector<int> v2)
{

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int i = 0, bs;

    while (i < v1.size())
    {
        bs = binarySearch(v2, v2.size(), v1[i]);
        if (bs == -1)
        {
            return false;
        }
        i++;
    }

    return true;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int ls = linearSearch(v, v.size(), 3);
    cout << "Linear Searched: " << ls << endl;

    int bs = binarySearch(v, v.size(), 3);
    cout << "Binary Searched: " << bs << endl;

    vector<int> v1 = {1, 3, 4, 5, 2};
    vector<int> v2 = {2, 4, 3, 1, 7, 5, 15};
    bool is = isSubset(v1, v2);
    cout << (is ? "Yes, v1 is subset of v2" : "No, v1 is not subset of v2") << endl;

    return 0;
}