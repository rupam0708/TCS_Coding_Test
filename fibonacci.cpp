#include <iostream>
#include <vector>
using namespace std;

vector<int> get_fib(int n)
{
    int a = 0, b = 1;
    vector<int> v = {0, 1};
    while (v.size() <= n)
    {
        v.push_back(v[a++] + v[b++]);
    }

    return v;
}

int get_fib2(int n)
{
    if (n <= 1)
        return n;

    int last = get_fib2(n - 1);
    int slast = get_fib2(n - 2);

    return last + slast;
}

int factorial(int n)
{
    if (n == 0 || n == 1 || n == 2)
        return n;
    else
    {
        int f = 1;
        for (int i = 1; i <= n; i++)
        {
            f *= i;
        }
        return f;
    }
}

int factorial2(int n)
{
    if (n == 0 || n == 1 || n == 2)
        return n;
    else
    {
        int f = factorial2(n - 1);
        return f * n;
    }
}

int main()
{
    int n = 5;
    vector<int> res = get_fib(n);
    for (int val : res)
        cout << val << " ";
    cout << endl;

    cout << get_fib2(n) << endl;

    cout << "Factorial of " << n << " = " << factorial(n) << endl;
    cout << "Factorial of " << n << " = " << factorial2(n) << endl;
    return 0;
}