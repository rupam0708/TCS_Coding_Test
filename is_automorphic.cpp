#include <iostream>
using namespace std;

int digits_num(int n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n /= 10;
    }

    return count;
}

bool is_automorphic(int n)
{
    if (n < 0)
        n = -n;                        // Handle negative input
    long long prod = (long long)n * n; // Use long long to prevent overflow

    int count = digits_num(n);
    long long divisor = 1;

    // Create a divisor to isolate the last 'count' digits
    for (int i = 0; i < count; i++)
    {
        divisor *= 10;
    }

    // Check if the last digits of the square match n
    return (prod % divisor) == n;
}

int main()
{
    cout << is_automorphic(76) << endl;
    return 0;
}