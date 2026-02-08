#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> leftRotateByOnePlace(vector<int> v, int n)
{
    int temp = v[0];
    for (int i = 0; i < n - 1; i++)
    {
        // swap(v[i], v[i + 1]);
        v[i] = v[i + 1];
    }
    v[n - 1] = temp;

    return v;
}

vector<int> rightRotateByOnePlace(vector<int> v, int n)
{
    int temp = v[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        // swap(v[i], v[i + 1]);
        v[i] = v[i - 1];
    }
    v[0] = temp;

    return v;
}

vector<int> leftRotateByK(vector<int> v, int n, int k)
{
    vector<int> temp = v;
    for (int i = k; i < n; i++)
    {
        v[i - k] = v[i];
    }

    for (int i = n - k; i < n; i++)
    {
        v[i] = temp[i - (n - k)];
    }

    return v;
}

vector<int> rightRotateByK(vector<int> v, int n, int k)
{
    vector<int> temp = v;
    for (int i = n - k; i < n; i++)
    {
        v[i - (n - k)] = v[i];
    }

    for (int i = k; i < n; i++)
    {
        v[i] = temp[i - k];
    }

    return v;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int k = 7;
    int n = v.size();

    if (k > n)
    {
        k %= n;
    }

    cout << "leftRotateByOnePlace" << endl;
    vector<int> rotated = leftRotateByOnePlace(v, n);

    for (int val : rotated)
        cout
            << val << " ";
    cout << endl;

    cout << "leftRotateK" << endl;
    rotated = leftRotateByK(v, n, k);

    for (int val : rotated)
        cout
            << val << " ";
    cout << endl;

    cout << "rightRotateByOnePlace" << endl;
    rotated = rightRotateByOnePlace(v, n);

    for (int val : rotated)
        cout
            << val << " ";
    cout << endl;

    cout << "rightRotateByK" << endl;
    rotated = rightRotateByK(v, n, k);

    for (int val : rotated)
        cout
            << val << " ";
    cout << endl;

    return 0;
}