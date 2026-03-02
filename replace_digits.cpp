#include <iostream>
using namespace std;

int reverse(int n)
{
    int rev = 0, ld;
    while (n > 0)
    {
        ld = n % 10;
        rev = rev * 10 + ld;
        n /= 10;
    }

    return rev;
}

int replace_0_1(int n)
{
    if (n == 0)
        return 1; // Special case for zero

    int new_num = 0;
    int place = 1;

    while (n > 0)
    {
        int ld = n % 10;
        if (ld == 0)
            ld = 1;

        // Build the number in the correct order using place value
        new_num = (ld * place) + new_num;

        place *= 10;
        n /= 10;
    }
    return new_num;
}

int main()
{
    cout << replace_0_1(102003) << endl;
    cout << reverse(102003) << endl;
    return 0;
}