#include <iostream>
using namespace std;

int factorial2(int n)
{
    if (n == 0)
        return 1;

    return n * factorial2(n - 1);
}

int factorial(int n)
{
    int res = 1;

    for (int i = n; i >= 1; i--)
    {
        res *= i;
    }

    return res;
}

bool is_strong_num(int n)
{
    int temp = n, sum = 0, ld;

    while (n > 0)
    {
        ld = n % 10;
        sum += factorial(ld);
        n /= 10;
    }

    return temp == sum;
}

int permutation(int n, int p)
{
    // N people can occupy P seats
    return factorial(n) / factorial(n - p);
}

int main()
{
    cout << factorial(5) << endl;
    cout << factorial2(5) << endl;
    cout << is_strong_num(145) << endl;
    cout << is_strong_num(26) << endl;
    cout << permutation(5, 3) << endl;

    return 0;
}