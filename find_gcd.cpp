#include <iostream>
#include <algorithm>
using namespace std;

int find_gcd(int n1, int n2)
{

    for (int i = 1; i <= min(n1, n2); i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            return i;
        }
    }

    return 1;
}

int find_lcm(int n1, int n2)
{

    return (n1 * n2) * find_gcd(n1, n2);
}

int main()
{
    cout << find_gcd(20, 15) << endl;
    cout << find_lcm(4, 8) << endl;
    return 0;
}