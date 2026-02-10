#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check_perfect(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (n % i == 0)
            sum += i;
    }

    if (sum == n)
        return true;

    return false;
}

bool check_perfect2(int n)
{
    int sum = 0;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i == n || i == 1)
            {
                sum += i;
            }
            else
            {
                sum = sum + i + n / i;
            }
        }
    }

    if (sum == n)
        return true;

    return false;
}

vector<int> all_divisors(int n)
{
    vector<int> res;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);

            if (i != n / i)
                res.push_back(n / i);
        }
    }

    sort(res.begin(), res.end());

    return res;
}

int main()
{
    cout << check_perfect(6) << endl;
    cout << check_perfect(15) << endl;
    cout << check_perfect(28) << endl;

    cout << endl;

    cout << check_perfect2(6) << endl;
    cout << check_perfect2(15) << endl;
    cout << check_perfect2(28) << endl;

    vector<int> res = all_divisors(6);
    for (int val : res)
        cout << val << " ";
    cout << endl;
    return 0;
}