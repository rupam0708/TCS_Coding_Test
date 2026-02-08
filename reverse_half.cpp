#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {7, 3, 1, 8, 4, 5};
    int n = v.size();
    sort(v.begin(), v.end());
    reverse(v.begin() + n / 2, v.end());

    for (int val : v)
        cout << val << " ";
    cout << endl;

    int sum = 0;
    for(int val : v)
        sum += val;

    cout << "Sum = " << sum << endl;
    return 0;
}