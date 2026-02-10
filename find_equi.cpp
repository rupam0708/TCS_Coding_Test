#include <iostream>
#include <vector>
using namespace std;

int find_equi(vector<int> v, int n)
{
    int sum = 0;
    for (int val : v)
        sum += val;

    int leftSum = 0, rightSum = sum;

    for (int i = 0; i < n; i++)
    {
        rightSum -= v[i];
        if (leftSum == rightSum)
            return i;

        leftSum += v[i];
    }

    return -1;
}

int main()
{
    vector<int> v = {2, 3, -1, 8, 4};
    int eq = find_equi(v, v.size());
    cout << "Equilibrium at = " << eq << endl;
    return 0;
}