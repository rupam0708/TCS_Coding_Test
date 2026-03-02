#include <iostream>
#include <vector>
using namespace std;

int missing_num(vector<int> v)
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] + 1 != v[i + 1])
            return v[i] + 1;
    }

    return -1;
}

int missing_num_2(vector<int> v)
{
    int n = v.size();

    int sum = n * (n + 1) / 2;

    int total = 0;

    for (int val : v)
        total += val;

    return sum - total;
}

int main()
{
    cout << missing_num({3, 0, 1}) << endl;
    cout << missing_num_2({3, 0, 1}) << endl;
    cout << missing_num_2({3, 2, 1}) << endl;
    return 0;
}