#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {5, 4, 3, 2, 1};
    for (int i = 0, j = v.size() - 1; i < j; i++, j--)
    {
        swap(v[j], v[i]);
    }

    for (int val : v)
    {
        cout << val << " ";
    }
    cout << endl;

    int i = 0, j = v.size() - 1;
    while(i < j)
    {
        swap(v[j--], v[i++]);
    }

    for (int val : v)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}