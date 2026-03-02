#include <iostream>
#include <vector>
using namespace std;

int getFirst(vector<int> v, int target)
{
    int n = v.size();
    int lo = 0, hi = n - 1;
    int res = -1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (v[mid] == target)
        {
            res = mid;
            hi = mid - 1;
        }
        else if (v[mid] < target)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return res;
}

int getSecond(vector<int> v, int target)
{
    int n = v.size();
    int lo = 0, hi = n - 1;
    int res = -1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (v[mid] == target)
        {
            res = mid;
            lo = mid + 1;
        }
        else if (v[mid] < target)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return res;
}

int main()
{
    vector<int> v = {1, 2, 2, 2, 4, 6, 7};
    int target = 2;
    cout << "First = " << getFirst(v, target) << endl;
    cout << "Second = " << getSecond(v, target) << endl;
    return 0;
}