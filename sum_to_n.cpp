#include <iostream>
#include <vector>
using namespace std;

int sum_to_n(int n)
{
    return (n * (n + 1)) / 2;
}

int sum_of_sq(int n)
{
    return (n * (n + 1) * ((2 * n) + 1)) / 6;
}

int sum_of_q(int n)
{
    return pow((n * (n + 1)) / 2, 2);
}

int sum_ap(vector<int> v)
{
    int n = v.size();

    if (n == 1)
        return v[0];
    else if (n == 2)
        return (v[0] + v[1]);
    else
    {
        return ((n / 2) * ((2 * v[0]) + (n - 1) * (v[1] - v[0])));
    }
}

int sum_gp(vector<int> v)
{
    int n = v.size();

    if (n == 1)
        return v[0];
    else if (n == 2)
        return (v[0] + v[1]);
    else
    {
        int r = v[1] / v[0];
        if (r < 1)
        {
            return (v[0] * (1 - pow(r, n))) / (1 - r);
        }
        else
        {
            return (v[0] * (pow(r, n) - 1)) / (r - 1);
        }
    }
}

int main()
{
    int n = 5;
    // cin >> n;
    cout << "Sum of " << n << " natural numbers = " << sum_to_n(n) << endl;
    cout << "Sum of squares of " << n << " natural numbers = " << sum_of_sq(n) << endl;
    cout << "Sum of qubes of " << n << " natural numbers = " << sum_of_q(n) << endl;

    vector<int> ap = {2, 4, 6, 8};
    cout << "Sum of AP = " << sum_ap(ap) << endl;

    vector<int> gp = {3, 9, 27, 81};
    cout << "Sum of GP = " << sum_gp(gp) << endl;
    return 0;
}