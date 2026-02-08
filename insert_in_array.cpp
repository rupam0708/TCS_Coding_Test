#include <iostream>
#include <vector>
using namespace std;

vector<int> insertBengin(vector<int> v, int n, int k)
{
    v.push_back(0);
    for (int i = n; i > 0; i--)
    {
        v[i] = v[i - 1];
    }
    v[0] = k;

    return v;
}

vector<int> insertEnd(vector<int> v, int n, int k)
{
    v.push_back(k);
    return v;
}

vector<int> insertAtPos(vector<int> v, int n, int k, int p)
{
    v.push_back(0);
    for (int i = n + 1; i > p - 1; i--)
    {
        v[i] = v[i - 1];
    }
    v[p-1] = k;

    return v;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    // int n = v.size();
    v = insertBengin(v, v.size(), 6);
    for (int val : v)
        cout << val << " ";
    cout << endl;

    v = insertEnd(v, v.size(), 7);
    for (int val : v)
        cout << val << " ";
    cout << endl;

    v = insertAtPos(v, v.size(), 8, 4);
    for (int val : v)
        cout << val << " ";
    cout << endl;

    return 0;
}